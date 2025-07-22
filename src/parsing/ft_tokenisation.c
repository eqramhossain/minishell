/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tokenisation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roussada <roussada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 11:41:22 by roussada          #+#    #+#             */
/*   Updated: 2025/07/22 16:39:36 by ehossain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// what about tokenisation the spaces.
void	ft_tokenisation(t_lexer *lexer)
{
	char	c;

	while (1)
	{
		ft_skip_whitespace(lexer);
		c = ft_peak(lexer);
		if (c == '\0')
			break ;
		else if (ft_check_operator(c)) // is a pipe or redirection
		{
			ft_lex_operator(lexer);
		}
		else if (c == '\'' || c == '"') // is a single or double qoute
		{
			ft_lex_quote(lexer);
		}
		else if (ft_isword(c)) // if char is a word
		{
			ft_lex_word(lexer);
		}
		else
			ft_advance(lexer);
	}
	ft_add_token(lexer, TOKEN_EOF, "EOF", 3);
}
