/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_redirection.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehossain <ehossain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 11:31:47 by ehossain          #+#    #+#             */
/*   Updated: 2025/10/23 11:31:49 by ehossain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

static t_redir	*create_redir(int type, char *file)
{
	t_redir	*redir;

	redir = (t_redir *)malloc(sizeof(t_redir));
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

static int	is_redir_token(t_token_type type)
{
	return (type == TOKEN_REDIR_IN || type == TOKEN_REDIR_OUT
		|| type == TOKEN_APPEND || type == TOKEN_HEREDOC);
}

t_redir	*ft_parse_redirections(t_token **tokens)
{
	t_redir	*redir_list;
	t_redir	*new_redir;
	int		redir_type;

	redir_list = NULL;
	while (*tokens && is_redir_token((*tokens)->type))
	{
		redir_type = (*tokens)->type;
		*tokens = (*tokens)->next;
		if (!*tokens || ((*tokens)->type != TOKEN_WORD
				&& (*tokens)->type != TOKEN_SINGLE_QUOTE
				&& (*tokens)->type != TOKEN_DOUBLE_QUOTE))
			return (redir_list);
		new_redir = create_redir(redir_type, (*tokens)->value);
		if (!new_redir)
		{
			ft_free_redir(redir_list);
			return (NULL);
		}
		ft_add_redir(&redir_list, new_redir);
		*tokens = (*tokens)->next;
	}
	return (redir_list);
}

void	ft_add_redir(t_redir **list, t_redir *new)
{
	t_redir	*current;

	if (!list || !new)
		return ;
	if (!*list)
	{
		*list = new;
		return ;
	}
	current = *list;
	while (current->next)
		current = current->next;
	current->next = new;
}
