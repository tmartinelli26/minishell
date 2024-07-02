/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   red.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebrandt <benoit.brandt@proton.me>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 13:16:17 by tmartin2          #+#    #+#             */
/*   Updated: 2024/07/02 20:06:23 by bebrandt         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

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
void here_doc(t_instruction *instruction, t_bash *bash) 
{
    (void)bash;
    char *limiter;
    pid_t reader;
    char *line;

    limiter = instruction->red->option;
    if (pipe(instruction->fd) == -1) 
    {
        perror("pipe");
        exit(EXIT_FAILURE);
    }
    printf("test\n");
    reader = fork();
    if (reader == 0) 
    {
        close(instruction->fd[0]);
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
            write(instruction->fd[1], line, strlen(line));
            write(instruction->fd[1], "\n", 1);
            free(line);
        }
    }
    else 
    {
        close(instruction->fd[1]);
        dup2(instruction->fd[0], STDIN_FILENO);
        wait(NULL);
    }
}

int	red(t_instruction *instruction, t_token *current_red)
{
	char	*red;
	int		file;
	int		i;

	file = 0;
	i = current_red->data_type;
	red = current_red->option;
	if ((instruction->save_stdout < 0) && (i & (OUTPUT_TRUNCATE | OUTPUT_APPEND)))
	{
		instruction->save_stdout = dup(STDOUT_FILENO);
		if (instruction->save_stdout < 0)
		{
			perror("dup");
			return (-1);
		}
	}
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

