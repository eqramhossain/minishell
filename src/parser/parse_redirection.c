/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_redirection.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekram <ekram@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 13:25:00 by ehossain          #+#    #+#             */
/*   Updated: 2025/10/21 18:26:07 by ekram            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

/*
** Create a new redirection node
** 
** type: TOKEN_REDIR_IN, TOKEN_REDIR_OUT, TOKEN_APPEND, or TOKEN_HEREDOC
** file: the filename or heredoc delimiter (quotes already removed)
*/
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
	ft_remove_quotes_inplace(redir->file);
	redir->fd = -1;
	redir->next = NULL;
	return (redir);
}

/*
** Check if current token is a redirection operator
*/
static int	is_redir_token(t_token_type type)
{
	return (type == TOKEN_REDIR_IN || type == TOKEN_REDIR_OUT
		|| type == TOKEN_APPEND || type == TOKEN_HEREDOC);
}

/*
** Parse all consecutive redirections from current position
** 
** Format: < infile > outfile >> append << heredoc
** Each redirection operator must be followed by a filename/delimiter
** 
** Returns: linked list of t_redir nodes, or NULL if no redirections
*/
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

/*
** Add a redirection to the end of the list
** Used to maintain order of redirections as they appear in input
*/
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
