/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_command_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekram <ekram@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/25 18:30:00 by ekram             #+#    #+#             */
/*   Updated: 2025/10/25 18:25:07 by ekram            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

int	ft_is_redir_token(t_token_type type)
{
	return (type == TOKEN_REDIR_IN || type == TOKEN_REDIR_OUT
		|| type == TOKEN_APPEND || type == TOKEN_HEREDOC);
}

t_redir	*ft_create_redir(int type, char *file)
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

int	ft_count_args(t_token *tokens)
{
	int	count;

	count = 0;
	while (tokens && tokens->type != TOKEN_PIPE && tokens->type != TOKEN_EOF)
	{
		if (ft_is_argument_token(tokens->type))
		{
			count++;
			tokens = tokens->next;
		}
		else if (tokens->type == TOKEN_REDIR_IN
			|| tokens->type == TOKEN_REDIR_OUT || tokens->type == TOKEN_APPEND
			|| tokens->type == TOKEN_HEREDOC)
		{
			tokens = tokens->next;
			if (tokens)
				tokens = tokens->next;
			continue ;
		}
		else
			tokens = tokens->next;
	}
	return (count);
}

void	ft_skip_redir_tokens(t_token **tokens)
{
	*tokens = (*tokens)->next;
	if (*tokens)
		*tokens = (*tokens)->next;
}

int	ft_add_merged_arg(char **argv, int i, t_token **tokens)
{
	char	*merged;

	merged = ft_merge_adjacent_tokens(tokens);
	if (!merged)
		return (-1);
	argv[i] = merged;
	return (i + 1);
}
