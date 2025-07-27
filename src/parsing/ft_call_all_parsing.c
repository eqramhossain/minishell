/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_call_all_parsing.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekram <ekram@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/25 15:17:19 by ehossain          #+#    #+#             */
/*   Updated: 2025/07/27 15:56:38 by ehossain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_all_parsing	*ft_call_all_parsing(t_all_parsing *all_parsing, char *rl)
{
	all_parsing->lexer = NULL;
	all_parsing->lexer = ft_lexing(rl, all_parsing->lexer);
	// ft_print_t_token(all_parsing->lexer);
	all_parsing->parser = ft_parser_init(all_parsing->lexer);
	all_parsing->ast = ft_parse_pipeline(all_parsing->parser);
	// ft_print_t_ast(all_parsing->ast);
	ft_print_ast_recursive(all_parsing->ast, 0, "");
	ft_free_all(all_parsing->ast, all_parsing->lexer, all_parsing->parser);
	free(all_parsing->prompt);
	return (all_parsing);
}
