/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_command.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekram <ekram@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 13:20:00 by ehossain          #+#    #+#             */
/*   Updated: 2025/10/22 14:24:16 by ehossain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

static int	is_redir_token(t_token_type type)
{
	return (type == TOKEN_REDIR_IN || type == TOKEN_REDIR_OUT
		|| type == TOKEN_APPEND || type == TOKEN_HEREDOC);
}

static t_redir	*create_redir(int type, char *file)
{
	t_redir	*redir;

	redir = malloc(sizeof(t_redir));
	if (!redir)
		return (NULL);
	redir->type = type;
	redir->file = ft_strdup(file);
	if (!redir->file)
	{
		free(redir);
		return (NULL);
	}
	redir->fd = -1;
	redir->next = NULL;
	return (redir);
}

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

char	**build_argv(t_token **tokens)
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
		if ((*tokens)->type == TOKEN_WORD
			|| (*tokens)->type == TOKEN_SINGLE_QUOTE
			|| (*tokens)->type == TOKEN_DOUBLE_QUOTE)
		{
			argv[i] = ft_strdup((*tokens)->value);
			if (!argv[i])
				return (NULL);
			i++;
			*tokens = (*tokens)->next;
		}
		else if ((*tokens)->type == TOKEN_REDIR_IN
			|| (*tokens)->type == TOKEN_REDIR_OUT
			|| (*tokens)->type == TOKEN_APPEND
			|| (*tokens)->type == TOKEN_HEREDOC)
		{
			*tokens = (*tokens)->next;
			if (*tokens)
				*tokens = (*tokens)->next;
			continue ;
		}
		else
			*tokens = (*tokens)->next;
	}
	argv[i] = NULL;
	return (argv);
}

t_cmd	*ft_parse_command(t_token **tokens)
{
	t_cmd	*cmd;
	char	**argv;
	t_redir	*redir;
	int		argc;
	int		i;
	int		redir_type;

	if (!tokens || !*tokens)
		return (NULL);
	cmd = ft_calloc(1, sizeof(t_cmd));
	if (!cmd)
		return (NULL);
	cmd->argv = NULL;
	cmd->redir = NULL;
	cmd->next = NULL;
	argc = count_args(*tokens);
	argv = malloc(sizeof(char *) * (argc + 1));
	if (!argv)
	{
		free(cmd);
		return (NULL);
	}
	i = 0;
	while (*tokens && (*tokens)->type != TOKEN_PIPE
		&& (*tokens)->type != TOKEN_EOF)
	{
		if (is_redir_token((*tokens)->type))
		{
			redir_type = (*tokens)->type;
			*tokens = (*tokens)->next;
			if (!*tokens || ((*tokens)->type != TOKEN_WORD
					&& (*tokens)->type != TOKEN_SINGLE_QUOTE
					&& (*tokens)->type != TOKEN_DOUBLE_QUOTE))
			{
				free(argv);
				ft_free_cmd(cmd);
				return (NULL);
			}
			redir = create_redir(redir_type, (*tokens)->value);
			if (!redir)
			{
				free(argv);
				ft_free_cmd(cmd);
				return (NULL);
			}
			ft_add_redir(&cmd->redir, redir);
			*tokens = (*tokens)->next;
		}
		else if ((*tokens)->type == TOKEN_WORD
			|| (*tokens)->type == TOKEN_SINGLE_QUOTE
			|| (*tokens)->type == TOKEN_DOUBLE_QUOTE)
		{
			argv[i] = ft_strdup((*tokens)->value);
			if (!argv[i])
			{
				while (--i >= 0)
					free(argv[i]);
				free(argv);
				ft_free_cmd(cmd);
				return (NULL);
			}
			i++;
			*tokens = (*tokens)->next;
		}
		else
		{
			*tokens = (*tokens)->next;
		}
	}
	argv[i] = NULL;
	cmd->argv = argv;
	return (cmd);
}
