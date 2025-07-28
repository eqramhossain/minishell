/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lex_word.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehossain <ehossain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 16:37:24 by ehossain          #+#    #+#             */
/*   Updated: 2025/07/24 13:26:26 by ehossain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_lex_word(t_lexer *lexer)
{
	char		c;
	const char	*start;
	size_t		len;

	start = &lexer->input[lexer->pos];
	len = 0;
	while (lexer->input[lexer->pos])
	{
		c = ft_peak(lexer);
		if (c == '\0' || c == 32 || ft_check_operator(c) || c == '\''
			|| c == '"')
			break ;
		ft_advance(lexer);
		len++;
	}
	if (len > 0)
		ft_add_token(lexer, TOKEN_WORD, (char *)start, len);
}
