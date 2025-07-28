/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roussada <roussada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 13:12:55 by roussada          #+#    #+#             */
/*   Updated: 2025/07/26 10:58:06 by ehossain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	ft_init_node(t_ast *node);
static int	ft_handle_redirection(t_parser *parser, t_ast *node);
static void	ft_add_redirection(t_ast *cmd, int type, char *file);
static void	ft_free_redirections(t_redir *redir);

t_ast	*ft_parse_pipeline(t_parser *parser)
{
	t_ast *pipe_connector; // The command we start with
	t_ast *first_command;  // Joins two commands left & right of a pipe
	t_ast *pipe_node;      // Our chain of pipe that keeps growing
	// STEP 1: Get the very first command
	first_command = ft_parse_command(parser);
	if (!first_command)
		return (NULL); // Oops, no valid command found!
	// Start pipe_node with the first command
	pipe_node = first_command;
	// Keep adding pipes as long as we find them
	while (ft_parser_match(parser, TOKEN_PIPE))
	{
		// Create a new pipe connector
		pipe_connector = malloc(sizeof(t_ast));
		pipe_connector->type = "pipe";
		// Connect what we have so far to the left side
		pipe_connector->left = pipe_node;
		// Get the next command for the right side
		pipe_connector->right = ft_parse_command(parser);
		// Safety check: did we get a valid right command?
		if (!pipe_connector->right)
		{
			ft_strerror("Syntax error: expected argument after pipe");
			return (NULL);
		}
		// Our chain now includes this new pipe connection
		pipe_node = pipe_connector;
	}
	return (pipe_node);
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

/**
 * @brief inisialize the t_ast structure
 *
 * @param node
 */
static void	ft_init_node(t_ast *node)
{
	node->type = "command";
	node->argv = malloc(sizeof(char *) * 256);
	node->left = NULL;
	node->right = NULL;
	node->redirs = NULL;
}

/**
 * @brief This is a safe accessor function that retrieves the token at
 * the parser's current position without advancing that positio
 *
 * @param parser
 * @return Returns a pointer to the current t_token if one exists
 */
t_token	*ft_parser_current(t_parser *parser)
{
	if (parser->pos < parser->token_count)
		return (parser->tokens[parser->pos]);
	return (NULL);
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
		ft_strerror("Syntax error: expected file after redirection\n");
		return (0);
		// changed exit to return. cause it exit the program when there is a sytax error.
	}
	ft_add_redirection(node, redir_type, file_token->text);
	parser->pos++;
	return (1);
}

static void	ft_add_redirection(t_ast *cmd, int type, char *file)
{
	t_redir	*redir;

	redir = malloc(sizeof(t_redir));
	redir->type = type;
	redir->file = file;
	redir->next = cmd->redirs;
	cmd->redirs = redir;
}

static void	ft_free_redirections(t_redir *redir)
{
	t_redir	*tmp;

	while (redir)
	{
		tmp = redir->next;
		free(redir);
		redir = tmp;
	}
}
