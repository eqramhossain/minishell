/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_command.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekram <ekram@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 11:31:54 by ehossain          #+#    #+#             */
/*   Updated: 2025/10/25 18:26:32 by ehossain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

static t_cmd	*init_cmd(void)
{
	t_cmd	*cmd;

	cmd = ft_calloc(1, sizeof(t_cmd));
	if (!cmd)
		return (NULL);
	cmd->pid = -1;
	cmd->argv = NULL;
	cmd->argc = -1;
	cmd->redir = NULL;
	cmd->pipe_fd[0] = -1;
	cmd->pipe_fd[1] = -1;
	cmd->next = NULL;
	return (cmd);
}

static int	handle_redir(t_token **tokens, t_cmd *cmd)
{
	t_redir	*redir;
	int		redir_type;

	redir_type = (*tokens)->type;
	*tokens = (*tokens)->next;
	if (!*tokens || ((*tokens)->type != TOKEN_WORD
			&& (*tokens)->type != TOKEN_SINGLE_QUOTE
			&& (*tokens)->type != TOKEN_DOUBLE_QUOTE))
		return (0);
	redir = ft_create_redir(redir_type, (*tokens)->value);
	if (!redir)
		return (0);
	ft_add_redir(&cmd->redir, redir);
	*tokens = (*tokens)->next;
	return (1);
}

static int	add_word_to_argv(char **argv, int i, t_token **tokens)
{
	argv[i] = ft_strdup((*tokens)->value);
	if (!argv[i])
		return (-1);
	*tokens = (*tokens)->next;
	return (i + 1);
}

static int	parse_tokens(t_token **tokens, t_cmd *cmd, char **argv)
{
	int	i;

	i = 0;
	while (*tokens && (*tokens)->type != TOKEN_PIPE
		&& (*tokens)->type != TOKEN_EOF)
	{
		if (ft_is_redir_token((*tokens)->type))
		{
			if (!handle_redir(tokens, cmd))
				return (-1);
		}
		else if ((*tokens)->type == TOKEN_WORD
			|| (*tokens)->type == TOKEN_SINGLE_QUOTE
			|| (*tokens)->type == TOKEN_DOUBLE_QUOTE)
		{
			i = add_word_to_argv(argv, i, tokens);
			if (i == -1)
				return (-1);
		}
		else
			*tokens = (*tokens)->next;
	}
	return (i);
}

t_cmd	*ft_parse_command(t_token **tokens)
{
	t_cmd	*cmd;
	char	**argv;
	int		result;

	if (!tokens || !*tokens)
		return (NULL);
	cmd = init_cmd();
	if (!cmd)
		return (NULL);
	argv = malloc(sizeof(char *) * (ft_count_args(*tokens) + 1));
	if (!argv)
		return (free(cmd), NULL);
	result = parse_tokens(tokens, cmd, argv);
	if (result == -1)
	{
		while (--result >= 0)
			free(argv[result]);
		free(argv);
		ft_free_cmd(cmd);
		return (NULL);
	}
	argv[result] = NULL;
	cmd->argv = argv;
	return (cmd);
}
