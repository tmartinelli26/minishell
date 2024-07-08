/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   red.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebrandt <benoit.brandt@proton.me>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 13:16:17 by tmartin2          #+#    #+#             */
/*   Updated: 2024/07/08 15:08:46 by bebrandt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/exec.h"

int	open_file(char *red, t_token *token)
{
	int	file;

	file = -1;
	if (OUTPUT_TRUNCATE & token->data_type)
		file = open(red, O_WRONLY | O_CREAT | O_TRUNC, 0777);
	if (OUTPUT_APPEND & token->data_type)
		file = open(red, O_WRONLY | O_CREAT | O_APPEND, 0777);
	if (INPUT & token->data_type)
		file = open(red, O_RDONLY);
	if (file < 0)
		print_cmd_error("minishell", red);
	return (file);
}

int here_doc(t_instruction *instruction, t_bash *bash, t_token *current_red)
{
    (void)bash;
    char *limiter;
    pid_t reader;
    char *line;

    limiter = current_red->option;
	if (inst_have_input_red(current_red->next) != 0)
		return (display_here_doc(limiter, instruction));
	if (pipe(instruction->fd_heredoc) == -1)
    {
        perror("pipe");
        return (-1);
    }
    reader = fork();
    if (reader == 0)
    {
		reset_fd_stdout(instruction);
        close(instruction->fd_heredoc[0]);
        while (1)
        {
            line = readline("> ");
            if (!line)
                exit(EXIT_SUCCESS);
            if (strncmp(line, limiter, strlen(limiter)) == 0 && line[strlen(limiter)] == '\0')
            {
                free(line);
                exit(EXIT_SUCCESS);
            }
            write(instruction->fd_heredoc[1], line, strlen(line));
            write(instruction->fd_heredoc[1], "\n", 1);
            free(line);
        }
    }
    else
    {
        close(instruction->fd_heredoc[1]);
        dup2(instruction->fd_heredoc[0], STDIN_FILENO);
        waitpid(reader, NULL, 0);
    }
	return (0);
}

int display_here_doc(char *limiter, t_instruction *instruction)
{
	pid_t reader;
	char *line;

	reader = fork();
    if (reader == 0)
    {
		reset_fd_stdout(instruction);
        while (1)
        {
            line = readline("> ");
            if (!line)
                exit(EXIT_SUCCESS);
            if (strncmp(line, limiter, strlen(limiter)) == 0 && line[strlen(limiter)] == '\0')
            {
                free(line);
                exit(EXIT_SUCCESS);
            }
            free(line);
        }
    }
    else
    {
        waitpid(reader, NULL, 0);
    }
	return (0);
}

int	red(t_instruction *instruction, t_token *current_red)
{
	(void)instruction;
	char	*red;
	int		file;
	int		i;

	file = 0;
	i = current_red->data_type;
	red = current_red->option;
	if (i & (OUTPUT_TRUNCATE | OUTPUT_APPEND))
	{
		file = open_file(red, current_red);
		if (file < 0)
			return (-1);
		dup2(file, STDOUT_FILENO);
		close(file);
	}
	if (i & INPUT)
	{
		file = open_file(red, current_red);
		if (file < 0)
			return (-1);
		dup2(file, STDIN_FILENO);
		close(file);
	}
	return (0);
}
