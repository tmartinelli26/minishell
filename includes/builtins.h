/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tommartinelli <tommartinelli@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 11:38:16 by tmartin2          #+#    #+#             */
/*   Updated: 2024/06/26 15:29:29 by tommartinel      ###   ########.fr       */
/*   By: bebrandt <benoit.brandt@proton.me>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 11:38:16 by tmartin2          #+#    #+#             */
/*   Updated: 2024/06/25 22:32:09 by bebrandt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTINS_H
# define BUILTINS_H

# include "minishell.h"
# include "exec.h"
// builtins/ft_exit.c

void ft_exit(t_instruction *instruction, t_bash *bash);

// builtins/pwd.c

void	pwd(t_instruction *instruction);

// builtins/cd.c

void	cd(t_instruction *instruction, t_env *env);
void	cd_go_home(t_instruction *instruction, t_env *env, char *oldpwd);
void	cd_move_dir(t_instruction *inst, char *dir, t_env *env, char *oldcwd);
void	set_cwd_env(t_instruction *inst, t_env *env, char *name, char *value);
void	ft_chdir_error(char *directory, int fd);

//builtins/env.c

void	print_env(t_env *env, t_instruction *instruction);

//builtins/echo.c

void	echo(t_instruction *instruciton);

//builtins/export.c

void	ft_export(t_env *env, t_instruction *instruction);
int		set_env_var_liste(t_env *env, char *envp);

//builtins/unset.c

void	ft_unset(t_env **env, t_instruction *instruction);

//builtins/utils_builtins.c

int		ft_strcmp(char *s1, char *s2);
char	*ft_strcat(char *dest, char *src);
char	*ft_strcpy(char *dest, char *src);

#endif
