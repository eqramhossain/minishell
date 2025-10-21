/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_variable.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehossain <ehossain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 20:31:38 by ehossain          #+#    #+#             */
/*   Updated: 2025/10/20 22:28:37 by ehossain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tokenizer.h"

static size_t	ft_get_variable_length(t_tokenizer *tokenizer);

t_token	*ft_handle_variable(t_tokenizer *tokenizer)
{
	size_t	len;
	char	*var_name;
	t_token	*token;
	size_t	i;

	ft_advance_tokenizer(tokenizer);
	len = ft_get_variable_length(tokenizer);
	if (len == 0)
		return (ft_create_token("$", TOKEN_WORD));
	var_name = ft_calloc(len + 2, sizeof(char));
	if (!var_name)
		return (NULL);
	var_name[0] = '$';
	i = 1;
	while (i <= len)
	{
		var_name[i] = tokenizer->curr_char;
		ft_advance_tokenizer(tokenizer);
		i++;
	}
	var_name[i] = '\0';
	token = ft_create_token(var_name, TOKEN_WORD);
	free(var_name);
	return (token);
}

static size_t	ft_get_variable_length(t_tokenizer *tokenizer)
{
	size_t	len;
	size_t	pos;

	len = 0;
	pos = tokenizer->curr_pos;
	if (tokenizer->input[pos] == '?')
		return (1);
	while (tokenizer->input[pos] && (ft_isalnum(tokenizer->input[pos])
			|| tokenizer->input[pos] == '_'))
	{
		len++;
		pos++;
	}
	return (len);
}
