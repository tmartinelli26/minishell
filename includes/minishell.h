/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebrandt <bebrandt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 11:16:35 by bebrandt          #+#    #+#             */
/*   Updated: 2024/05/20 10:42:18 by bebrandt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

// PERSONNAL LIB

# include "struct.h"
# include "error.h"
# include "../libft/includes/libft.h"

// readline lib

# include <readline/readline.h>
# include <readline/history.h>

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

// main/minishell.c

// main/prompt.c

void	prompt(void);

//lexer/lexer.c

void	lexing(t_bash *bash, char *sequence);

// parser/parser.c

int		parsing(t_bash *bash);

// builtins/builtins.c

void	builtins(void);

// exec/exec.c

void	exec(void);

// test/test.c

void	test_print_env(t_env *env);
void	test_print_instruction(t_instruction *instruction);
void	test_print_cmd_token(t_token *token);
void	test_print_red_token(t_token *token);

#endif
