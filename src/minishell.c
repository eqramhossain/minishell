/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehossain <ehossain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 19:07:35 by ehossain          #+#    #+#             */
/*   Updated: 2025/07/24 20:33:44 by ehossain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// maybe i can start the execution part
int	main(void)
{
	char		*rl;
	t_lexer		*lexer;
	t_parser	*parser;
	t_ast		*ast;
	char		*prompt;

	lexer = NULL;
	ft_display_banner();
	while (1)
	{
		prompt = ft_prompt();
		rl = readline(prompt);
		// printf("COLUMNS env: %s\n", getenv("COLUMNS"));
		if (!rl)
			continue ;
		if (*rl)
			add_history(rl);
		lexer = ft_lexing(rl, lexer);
		ft_print_token(lexer);
		parser = ft_parser_init(lexer);
		ast = ft_parse_pipeline(parser);
		ft_print_ast_recursive(ast, 0, "");
		ft_free_all(ast, lexer, parser);
		free(prompt);
		free(rl);
	}
	return (0);
}
