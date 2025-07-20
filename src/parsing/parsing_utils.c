/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roussada <roussada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 13:15:56 by roussada          #+#    #+#             */
/*   Updated: 2025/07/19 16:48:29 by ehossain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_print_redirs(t_redir *r, int indent)
{
	while (r)
	{
		for (int i = 0; i < indent; i++)
			printf("  ");
		printf("↳ REDIR: ");
		if (r->type == TOKEN_INPUT)
			printf("< ");
		else if (r->type == TOKEN_TRUNK)
			printf("> ");
		else if (r->type == TOKEN_APPEND)
			printf(">> ");
		else if (r->type == TOKEN_HEREDOC)
			printf("<< ");
		else
			printf("? ");
		printf("%s\n", r->file);
		r = r->next;
	}
}

void	ft_print_ast_recursive(t_ast *ast, int indent, const char *prefix)
{
	if (!ast)
		return ;
	for (int i = 0; i < indent; i++)
		printf("  ");
	printf("%s", prefix);
	if (ft_strcmp(ast->type, "pipe") == 0)
	{
		printf("┐ PIPE\n");
		ft_print_ast_recursive(ast->left, indent + 1, "├─ ");
		ft_print_ast_recursive(ast->right, indent + 1, "└─ ");
	}
	else if (ft_strcmp(ast->type, "command") == 0)
	{
		printf("└ COMMAND:");
		for (int i = 0; ast->argv && ast->argv[i]; i++)
			printf(" %s", ast->argv[i]);
		printf("\n");
		ft_print_redirs(ast->redirs, indent + 1);
	}
}

t_token	*ft_parser_current(t_parser *parser)
{
	if (parser->pos < parser->token_count)
		return (parser->tokens[parser->pos]);
	return (NULL);
}

int	ft_parser_match(t_parser *parser, int type)
{
	t_token	*current;

	current = ft_parser_current(parser);
	if (current && current->type == type)
	{
		parser->pos++;
		return (1);
	}
	return (0);
}

void	ft_parser_expect(t_parser *parser, int type)
{
	if (!ft_parser_match(parser, type))
	{
		perror("ERROR\n");
		exit(1);
	}
}
