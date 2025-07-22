/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_token.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehossain <ehossain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 16:39:22 by ehossain          #+#    #+#             */
/*   Updated: 2025/07/22 16:39:28 by ehossain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_add_token(t_lexer *lexer, int type, char *str, size_t len)
{
	t_token	*token;

	(void)len;
	if (lexer->token_count >= lexer->token_capacity)
	{
		lexer->token_capacity *= 2;
		lexer->tokens = ft_realloc(lexer->tokens, (lexer->token_capacity / 2)
				* sizeof(t_token *), lexer->token_capacity * sizeof(t_token *));
	}
	token = malloc(sizeof(t_token));
	token->type = type;
	token->text = ft_strdup(str);
	lexer->tokens[lexer->token_count++] = token;
}
