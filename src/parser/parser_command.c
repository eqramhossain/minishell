/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_command.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekram <ekram@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 13:20:00 by ehossain          #+#    #+#             */
/*   Updated: 2025/10/21 18:26:07 by ekram            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

/*
** Count arguments until we hit a pipe or EOF
** This helps us allocate the right size for argv array
*/
static int	count_args(t_token *tokens)
{
	int	count;

	count = 0;
	while (tokens && tokens->type != TOKEN_PIPE && tokens->type != TOKEN_EOF)
	{
		if (tokens->type == TOKEN_WORD || tokens->type == TOKEN_SINGLE_QUOTE
			|| tokens->type == TOKEN_DOUBLE_QUOTE)
			count++;
		else if (tokens->type == TOKEN_REDIR_IN
			|| tokens->type == TOKEN_REDIR_OUT || tokens->type == TOKEN_APPEND
			|| tokens->type == TOKEN_HEREDOC)
		{
			tokens = tokens->next;
			if (tokens)
				tokens = tokens->next;
			continue ;
		}
		tokens = tokens->next;
	}
	return (count);
}

/*
** Build the argv array from tokens
** Skip redirection tokens and their file arguments
** Process words and quoted strings
*/
static char	**build_argv(t_token **tokens)
{
	char	**argv;
	int		i;
	int		count;

	count = count_args(*tokens);
	argv = (char **)malloc(sizeof(char *) * (count + 1));
	if (!argv)
		return (NULL);
	i = 0;
	while (*tokens && (*tokens)->type != TOKEN_PIPE
		&& (*tokens)->type != TOKEN_EOF)
	{
		if ((*tokens)->type == TOKEN_WORD || (*tokens)->type == TOKEN_SINGLE_QUOTE
			|| (*tokens)->type == TOKEN_DOUBLE_QUOTE)
		{
			argv[i] = ft_strdup((*tokens)->value);
			if (!argv[i])
				return (NULL);
			ft_remove_quotes_inplace(argv[i]);
			i++;
			*tokens = (*tokens)->next;
		}
		else if ((*tokens)->type == TOKEN_REDIR_IN
			|| (*tokens)->type == TOKEN_REDIR_OUT
			|| (*tokens)->type == TOKEN_APPEND
			|| (*tokens)->type == TOKEN_HEREDOC)
		{
			break ;
		}
		else
			*tokens = (*tokens)->next;
	}
	argv[i] = NULL;
	return (argv);
}

/*
** Parse a single command with its arguments and redirections
** 
** Steps:
** 1. Parse any redirections that come before the command
** 2. Build the argv array from word tokens
** 3. Parse any redirections that come after arguments
** 4. Create and return the command structure
*/
t_cmd	*ft_parse_command(t_token **tokens)
{
	t_cmd	*cmd;
	t_redir	*more_redir;

	if (!tokens || !*tokens)
		return (NULL);
	cmd = (t_cmd *)malloc(sizeof(t_cmd));
	if (!cmd)
		return (NULL);
	cmd->argv = NULL;
	cmd->redir = NULL;
	cmd->next = NULL;
	cmd->redir = ft_parse_redirections(tokens);
	if (*tokens && (*tokens)->type != TOKEN_PIPE
		&& (*tokens)->type != TOKEN_EOF)
	{
		cmd->argv = build_argv(tokens);
		if (!cmd->argv)
		{
			ft_free_cmd(cmd);
			return (NULL);
		}
	}
	if (*tokens && (*tokens)->type != TOKEN_PIPE
		&& (*tokens)->type != TOKEN_EOF)
	{
		more_redir = ft_parse_redirections(tokens);
		if (more_redir)
			ft_add_redir(&cmd->redir, more_redir);
	}
	return (cmd);
}
