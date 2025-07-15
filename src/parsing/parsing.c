/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roussada <roussada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 13:12:55 by roussada          #+#    #+#             */
/*   Updated: 2025/07/15 13:47:45 by ehossain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_add_redirection(t_ast *cmd, int type, char *file)
{
	t_redir	*redir;

	redir = malloc(sizeof(t_redir));
	redir->type = type;
	redir->file = file;
	redir->next = cmd->redirs;
	cmd->redirs = redir;
}

static int	ft_handle_redirection(t_parser *parser, t_ast *node)
{
	int		redir_type;
	t_token	*file_token;

	redir_type = parser->tokens[parser->pos]->type;
	parser->pos++;
	file_token = ft_parser_current(parser);
	if (!file_token || file_token->type != TOKEN_WORD)
	{
		fprintf(stderr, "Syntax error: expected file after redirection\n");
		exit(1);
	}
	ft_add_redirection(node, redir_type, file_token->text);
	parser->pos++;
	return (1);
}

void	ft_init_node(t_ast *node)
{
	node->type = "command";
	node->argv = malloc(sizeof(char *) * 256);
	node->left = node->right = NULL;
	node->redirs = NULL;
}

void	ft_free_redirections(t_redir *redir)
{
	t_redir	*tmp;

	while (redir)
	{
		tmp = redir->next;
		free(redir);
		redir = tmp;
	}
}

t_ast	*ft_parse_command(t_parser *parser)
{
	t_ast	*node;
	size_t	argc;
	t_token	*token;

	node = malloc(sizeof(t_ast));
	ft_init_node(node);
	argc = 0;
	while ((token = ft_parser_current(parser)))
	{
		if (token->type == TOKEN_WORD)
			node->argv[argc++] = token->text, parser->pos++;
		else if (token->type >= TOKEN_INPUT && token->type <= TOKEN_HEREDOC)
			ft_handle_redirection(parser, node);
		else
			break ;
	}
	node->argv[argc] = NULL;
	if (argc == 0 && !node->redirs)
	{
		ft_free_redirections(node->redirs);
		free(node->argv);
		free(node);
		return (NULL);
	}
	return (node);
}

t_ast	*ft_parse_pipeline(t_parser *parser)
{
	t_ast	*left;
	t_ast	*pipe_node;

	left = ft_parse_command(parser);
	if (!left)
		return (NULL);
	while (ft_parser_match(parser, TOKEN_PIPE))
	{
		pipe_node = malloc(sizeof(t_ast));
		pipe_node->type = "pipe";
		pipe_node->left = left;
		pipe_node->right = ft_parse_command(parser);
		if (!pipe_node->right)
		{
			perror("sytax error after |\n");
			exit(1);
		}
		left = pipe_node;
	}
	return (left);
}

t_parser	*ft_parser_init(t_lexer *lexer)
{
	t_parser	*parser;

	parser = malloc(sizeof(t_parser));
	parser->tokens = lexer->tokens;
	parser->pos = 0;
	parser->token_count = lexer->token_count;
	return (parser);
}
