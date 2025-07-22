/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lexing.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehossain <ehossain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 16:33:54 by ehossain          #+#    #+#             */
/*   Updated: 2025/07/21 00:29:35 by ehossain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_lexer	*ft_lexing(char *str, t_lexer *lexer)
{
	lexer = malloc(sizeof(t_lexer));
	if (!lexer)
		exit(EXIT_FAILURE);
	lexer->input = str;
	lexer->pos = 0;
	lexer->token_count = 0;
	lexer->token_capacity = 64;
	// why the token token_capacity is 64
	// what will happen if i have to work with more than 64 char
	lexer->tokens = malloc(sizeof(t_token *) * lexer->token_capacity);
	if (!lexer->tokens)
	{
		free(lexer);
		exit(EXIT_FAILURE);
	}
	ft_tokenisation(lexer);
	return (lexer);
}
