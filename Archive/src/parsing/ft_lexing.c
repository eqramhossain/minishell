/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lexing.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehossain <ehossain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 16:33:54 by ehossain          #+#    #+#             */
/*   Updated: 2025/07/24 14:53:57 by ehossain         ###   ########.fr       */
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
	lexer->tokens = malloc(sizeof(t_token *) * lexer->token_capacity);
	if (!lexer->tokens)
	{
		free(lexer);
		exit(EXIT_FAILURE);
	}
	ft_tokenisation(lexer);
	return (lexer);
}
