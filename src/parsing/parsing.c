/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roussada <roussada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 13:12:55 by roussada          #+#    #+#             */
/*   Updated: 2025/07/19 17:35:13 by ehossain         ###   ########.fr       */
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
		return (0);
		// changed exit to return. cause it exit the program when there is a sytax error.
	}
	ft_add_redirection(node, redir_type, file_token->text);
	parser->pos++;
	return (1);
}

void	ft_init_node(t_ast *node)
{
	node->type = "command";
	node->argv = malloc(sizeof(char *) * 256);
	// why allocate 256 pointer to char ??
	// what if the argv has to deal with more that 256 char *
	node->left = NULL;
	node->right = NULL;
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
	size_t	argc;
	t_ast	*node;
	t_token	*token;

	argc = 0;
	node = malloc(sizeof(t_ast));
	ft_init_node(node);
	while ((token = ft_parser_current(parser)))
	{
		if (token->type == TOKEN_WORD)
			node->argv[argc++] = token->text, parser->pos++;
		else if (token->type >= TOKEN_INPUT && token->type <= TOKEN_HEREDOC)
		{
			if (ft_handle_redirection(parser, node) == 0)
				break ;
			// there was a exit before so whenever there is a problem the shell exited unexpectedly
		}
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
			// perror("sytax error after | pipe");
			// perror is inutile here use ft_strerror
			ft_strerror("Syntax error: expected argument after pipe");
			// exit(1);
			return (NULL);
			// changed exit to return for unexpected exit reason
		}
		left = pipe_node;
	}
	return (left);
}
