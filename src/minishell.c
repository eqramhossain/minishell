/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekram <ekram@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 14:45:25 by ehossain          #+#    #+#             */
/*   Updated: 2025/07/15 13:35:06 by ehossain         ###   ########.fr       */
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
	ft_tokenisation(lexer);
	// print_token(lexer);
	return (lexer);
}
int	main(void)
{
	char		*rl;
	t_lexer		*lexer;
	t_parser	*parser;
	t_ast		*ast;

	lexer = NULL;
	while (1)
	{
		rl = readline("minishell>");
		if (!rl)
			break ;
		if (*rl)
			add_history(rl);
		lexer = ft_lexing(rl, lexer);
		parser = ft_parser_init(lexer);
		ast = ft_parse_pipeline(parser);
		ft_print_ast_recursive(ast, 0, "");
		ft_free_all(ast, lexer, parser);
		free(rl);
	}
	return (0);
}
