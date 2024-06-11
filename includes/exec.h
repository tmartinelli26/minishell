/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmartin2 <tmartin2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 14:35:50 by tmartin2          #+#    #+#             */
/*   Updated: 2024/06/11 10:47:05 by tmartin2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXEC_H
# define EXEC_H

# include "minishell.h"

// exec/sort_array.c

void	sort_red(t_instruction *instruction, t_env *env);

// exec/ft_cmd.c

void ft_cmd(t_instruction *instruction, t_env *env, char **envp);

// exec/process.c

void child_process(t_instruction *instruction, t_env *env, char **envp, int prev_fd[2]);

// exec/red.c

void red(t_instruction *instruction);
int open_file(char *red, int i);
void here_doc(t_instruction *instruction);

// exec/sort_cmd_builtin

void sort_cmd_builtin(t_instruction *instruction, t_env *env, char **envp);

// exec/utils_exec.c

int	ft_get_next_line(char **line);

#endif