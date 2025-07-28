/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lex_qoute.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehossain <ehossain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 16:38:03 by ehossain          #+#    #+#             */
/*   Updated: 2025/07/22 16:38:12 by ehossain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_lex_quote(t_lexer *lexer)
{
	char		c;
	const char	*start;
	size_t		len;

	c = ft_advance(lexer);
	start = &lexer->input[lexer->pos];
	len = 0;
	while (ft_peak(lexer) != c && ft_peak(lexer) != '\0')
	{
		ft_advance(lexer);
		len++;
	}
	if (ft_peak(lexer) == c)
		ft_advance(lexer);
	else
	{
		ft_add_token(lexer, TOKEN_ERROR, (char *)start, len);
		return ;
	}
	ft_add_token(lexer, TOKEN_WORD, (char *)start, len);
}
