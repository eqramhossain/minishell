/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lex_operator.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehossain <ehossain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 16:38:54 by ehossain          #+#    #+#             */
/*   Updated: 2025/07/22 16:39:03 by ehossain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_lex_operator(t_lexer *lexer)
{
	char	c;

	c = ft_advance(lexer);
	if (c == '|')
		ft_add_token(lexer, TOKEN_PIPE, "|", 1);
	else if (c == '>')
	{
		if (ft_peak(lexer) == '>')
		{
			ft_advance(lexer);
			ft_add_token(lexer, TOKEN_APPEND, ">>", 2);
		}
		else
			ft_add_token(lexer, TOKEN_TRUNK, ">", 1);
	}
	else if (c == '<')
	{
		if (ft_peak(lexer) == '<')
		{
			ft_advance(lexer);
			ft_add_token(lexer, TOKEN_HEREDOC, "<<", 2);
		}
		else
			ft_add_token(lexer, TOKEN_INPUT, "<", 1);
	}
}
