/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekram <ekram@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 14:45:25 by ehossain          #+#    #+#             */
/*   Updated: 2025/07/15 17:34:19 by ehossain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

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
