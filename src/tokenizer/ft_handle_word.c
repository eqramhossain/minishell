/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_word.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehossain <ehossain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 18:23:48 by ehossain          #+#    #+#             */
/*   Updated: 2025/10/20 20:47:22 by ehossain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tokenizer.h"

static size_t	ft_get_word_length(t_tokenizer *tokenizer);

t_token	*ft_handle_word(t_tokenizer *tokenizer)
{
	size_t	len;
	size_t	i;
	char	*word;
	t_token	*token;

	i = 0;
	len = ft_get_word_length(tokenizer);
	if (len == 0)
		return (NULL);
	word = ft_calloc(len + 1, sizeof(char));
	if (!word)
		return (NULL);
	while (i < len)
	{
		word[i] = tokenizer->curr_char;
		ft_advance_tokenizer(tokenizer);
		i++;
	}
	word[i] = '\0';
	token = ft_create_token(word, TOKEN_WORD);
	free(word);
	return (token);
}

static size_t	ft_get_word_length(t_tokenizer *tokenizer)
{
	size_t	len;
	size_t	pos;

	len = 0;
	pos = tokenizer->curr_pos;
	while (tokenizer->input[pos] && !ft_is_whitespace(tokenizer->input[pos])
		&& !ft_is_operator_char(tokenizer->input[pos])
		&& !ft_is_quote(tokenizer->input[pos]) && tokenizer->input[pos] != '$')
	{
		len++;
		pos++;
	}
	return (len);
}
