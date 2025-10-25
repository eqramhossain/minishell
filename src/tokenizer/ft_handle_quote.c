/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_quote.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekram <ekram@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 20:27:30 by ehossain          #+#    #+#             */
/*   Updated: 2025/10/25 15:04:41 by ekram            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tokenizer.h"

static size_t	ft_get_quoted_length(t_tokenizer *tokenizer, char quote);
static char		*ft_extract_quoted_string(t_tokenizer *tokenizer, char quote,
					size_t len);

t_token	*ft_handle_quotes(t_tokenizer *tokenizer)
{
	char			quote_char;
	size_t			len;
	char			*quoted_str;
	t_token			*token;
	t_token_type	type;

	quote_char = tokenizer->curr_char;
	len = ft_get_quoted_length(tokenizer, quote_char);
	quoted_str = ft_extract_quoted_string(tokenizer, quote_char, len);
	if (!quoted_str)
		return (NULL);
	if (quote_char == '\'')
		type = TOKEN_SINGLE_QUOTE;
	else
		type = TOKEN_DOUBLE_QUOTE;
	token = ft_create_token(quoted_str, type);
	free(quoted_str);
	return (token);
}

static size_t	ft_get_quoted_length(t_tokenizer *tokenizer, char quote)
{
	size_t	len;
	size_t	pos;

	len = 0;
	pos = tokenizer->curr_pos + 1;
	while (tokenizer->input[pos] && tokenizer->input[pos] != quote)
	{
		len++;
		pos++;
	}
	return (len);
}

static char	*ft_extract_quoted_string(t_tokenizer *tokenizer, char quote,
		size_t len)
{
	char	*str;
	size_t	i;

	str = (char *)malloc(sizeof(char) * (len + 3));
	if (!str)
		return (NULL);
	str[0] = quote;
	i = 1;
	ft_advance_tokenizer(tokenizer);
	while (i <= len && tokenizer->curr_char != quote)
	{
		str[i] = tokenizer->curr_char;
		ft_advance_tokenizer(tokenizer);
		i++;
	}
	str[i] = quote;
	str[i + 1] = '\0';
	if (tokenizer->curr_char == quote)
		ft_advance_tokenizer(tokenizer);
	return (str);
}
