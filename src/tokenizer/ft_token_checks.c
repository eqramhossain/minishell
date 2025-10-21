/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_token_checks.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehossain <ehossain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 18:18:53 by ehossain          #+#    #+#             */
/*   Updated: 2025/10/20 22:33:50 by ehossain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tokenizer.h"

bool	ft_is_whitespace(char c)
{
	if (c == ' ' || c == '\t' || c == '\n' || c == '\r')
		return (TRUE);
	return (FALSE);
}

bool	ft_is_operator_char(char c)
{
	if (c == '|' || c == '<' || c == '>')
		return (TRUE);
	return (FALSE);
}

bool	ft_is_quote(char c)
{
	if (c == '\'' || c == '"')
		return (TRUE);
	return (FALSE);
}

void	ft_skip_whitespaces(t_tokenizer *tokenizer)
{
	while (tokenizer->curr_char != '\0'
		&& ft_is_whitespace(tokenizer->curr_char))
	{
		ft_advance_tokenizer(tokenizer);
	}
}
