/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tommartinelli <tommartinelli@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 17:12:23 by bebrandt          #+#    #+#             */
/*   Updated: 2024/06/28 13:54:48 by tommartinel      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*   Updated: 2024/06/13 12:45:59 by bebrandt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

typedef struct s_bash
{
	char					*working_directory;
	char					*sequence;
	int						exit_code;
	char					**envp;
	struct s_env			*env;
	struct s_instruction	*instruction;
}							t_bash;

typedef struct s_env
{
	char					*name;
	char					*value;
	struct s_env			*next;
}							t_env;

typedef struct s_instruction
{
	struct s_token			*red;
	struct s_token			*cmd;
	int						fd[2];
	pid_t					pid;
	int						exit_status;
	char					**cmd_array;
	struct s_instruction	*prev;
	struct s_instruction	*next;
}							t_instruction;

typedef struct s_token
{
	char					*data;
	int						data_type;
	char					*option;
	int						option_type;
	struct s_token			*next;
}							t_token;

// binary flags to define a cmd type

enum
{
	REDIRECTION = 1,
	INPUT = 2 ,
	HEREDOC = 4,
	HERESTRING = 8,
	OUTPUT_TRUNCATE = 16,
	OUTPUT_APPEND = 32,
	D_QUOTES = 64,
	S_QUOTES = 128,
	BUILTIN = 256,
	CMD = 512,
	WORD = 1024
};

// struct_utils/init.c

void			init_bash(t_bash **bash, char **envp);
t_env			*init_env(char **envp);
t_instruction	*init_instruction(void);
t_token			*init_token(void);

// struct_utils/new.c

t_env			*new_env(char *name_to_value);
t_instruction	*new_instruction(void);
t_token			*new_token(void);

// struct_utils/add_back.c

void			add_back_env(t_env **env, t_env *new);
void			add_back_instruction(t_instruction **inst, t_instruction *new);
void			add_back_token(t_token **token, t_token *new);

// struct_utils/last.c

t_env			*last_env(t_env *env);
t_instruction	*last_instruction(t_instruction *inst);
t_token			*last_token(t_token *token);

// struct_utils/size.c

int				size_instruction(t_instruction *instruction);
int				size_token(t_token *token);

// struct_utils/clear_all.c

void			*clear_bash_and_exit(t_bash **bash, int exit_code);
void			*clear_bash(t_bash **bash);
void			*clear_env(t_env **env);
void			*clear_instruction(t_instruction **instruction);
void			*clear_token(t_token **token);

// struct_utils/clear_one.c

// struct_utils/env_utils.c

char			*get_value(t_env *env, char *name);
char			*get_name_to_value(char *name, char *value);
int				name_exist(t_env *env, char *name);
int				names_are_the_same(char *name, char *name_to_check);
void			update_value(t_env *env, char *name, char *value);

// struct_utils/bash_utils.c

void			reset_buffer(char *buffer);

#endif
