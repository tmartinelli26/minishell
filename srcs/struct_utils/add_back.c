/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_back.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebrandt <bebrandt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 22:31:19 by bebrandt          #+#    #+#             */
/*   Updated: 2024/05/18 10:19:33 by bebrandt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	add_back_env(t_env **env, t_env *new)
{
	t_env	*last;

	if (!env || !new)
		return ;
	last = last_env(*env);
	if (!*env)
		*env = new;
	else
		last->next = new;
}

void	add_back_instruction(t_instruction **inst, t_instruction *new)
{
	t_instruction	*last;

	if (!inst || !new)
		return ;
	last = last_instruction(*inst);
	if (!*inst)
		*inst = new;
	else
		last->next = new;
}

void	add_back_token(t_token **token, t_token *new)
{
	t_token	*last;

	if (!token || !new)
		return ;
	last = last_token(*token);
	if (!*token)
		*token = new;
	else
		last->next = new;
}
