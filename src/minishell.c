/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehossain <ehossain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 19:07:35 by ehossain          #+#    #+#             */
/*   Updated: 2025/07/20 23:28:22 by ehossain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	main(void)
{
	char		*rl;
	char		*prompt;
	t_lexer		*lexer;
	t_parser	*parser;
	t_ast		*ast;

	lexer = NULL;
	ft_display_banner();
	while (1)
	{
		prompt = ft_prompt();
		rl = readline(prompt);
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
