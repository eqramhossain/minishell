/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_t_token.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehossain <ehossain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/25 19:10:39 by ehossain          #+#    #+#             */
/*   Updated: 2025/07/25 19:15:11 by ehossain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	ft_print_token(t_lexer *lexer)
{
	size_t	i;
	t_token	*token;

	i = 0;
	while (i < lexer->token_count)
	{
		token = lexer->tokens[i];
		printf("Token Number : %zu, Token: Type %d, Text: \"%s\"\n", i + 1,
			token->type, token->text);
		i++;
	}
}
