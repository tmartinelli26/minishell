/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tommartinelli <tommartinelli@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 14:35:50 by tmartin2          #+#    #+#             */
/*   Updated: 2024/06/27 12:59:44 by tommartinel      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXEC_H
# define EXEC_H

# include "minishell.h"
# include "parser.h"
// exec/sort_array.c

void	sort_red(t_instruction *instruction, t_bash *bash);

// exec/ft_cmd.c

void ft_cmd(t_instruction *instruction, t_env *env, char **envp);
int given_path(t_instruction *instruction, char **envp);

// exec/process.c

void ft_exit(t_instruction *instruction, t_bash *bash);
void child_process(t_instruction *instruction, t_bash *bash, char **envp);
void parent_process(t_instruction *instruction);

// exec/red.c

void red(t_instruction *instruction);
int open_file(char *red, t_token *token);
void here_doc(t_instruction *instruction, t_bash *bash);
// exec/sort_cmd_builtin

void sort_cmd_builtin(t_instruction *instruction, t_bash *bash, char **envp);

// exec/utils_exec.c

int	ft_get_next_line(char **line);
int	ft_strcmp(char *s1, char *s2);
int is_digit_only(char *str);
int handle_exit_error(int arg_count, t_token *current_red, t_instruction *instruction);

// exec/exec.c

void	set_exit_code(t_bash *bash);

// exec/multi_exec.c

void multi_exec(t_bash *bash, t_instruction *instruction, char **envp);

#endif