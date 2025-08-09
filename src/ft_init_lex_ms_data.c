/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_lex_ms_data.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehossain <ehossain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 20:09:12 by ehossain          #+#    #+#             */
/*   Updated: 2025/08/04 13:36:14 by ehossain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "tokenize.h"

void	ft_inisialize_t_ms_data(t_ms_data *data, char **envp)
{
	data->input = NULL;
	data->prompt = NULL;
	data->envp = ft_get_envp(envp);
	if (!data->envp)
		return ;
	data->token = ft_tokenizer_init();
	if (data->token)
		return ;
}

t_token	*ft_tokenizer_init(void)
{
	t_token	*token;

	token = ft_calloc(sizeof(t_token), 1);
	if (!token)
		return (NULL);
	token->value = NULL;
	token->type = 0;
	token->next = NULL;
	return (token);
}
