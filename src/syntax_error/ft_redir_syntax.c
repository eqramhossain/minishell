/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_redir_syntax.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekram <ekram@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 14:33:27 by gmarquis          #+#    #+#             */
/*   Updated: 2025/10/18 15:18:31 by ekram            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "syntax.h"

/*
** Handles input redirection: '<' and '<<' (heredoc)
** 
** Error cases:
** - Consecutive redirections: "< <", "< <<", etc.
** - Redirection at end of line (no filename)
** 
** Returns: 1 if error detected, 0 if valid
*/

static int	st_redir_in(t_syntax **syntax)
{
	t_syntax	*synt;

	synt = *syntax;
	if (synt->current[synt->i + 1] && synt->current[synt->i + 1] == '<')
	{
		if (synt->r_in || synt->r_here || synt->r_out || synt->r_app)
			return (synt->error = 3, 1);
		synt->i++;
		if (synt->i == synt->len_end)
			synt->error = 1;
		synt->r_here = 1;
	}
	else
	{
		if (synt->r_in || synt->r_here || synt->r_out || synt->r_app)
			return (synt->error = 2, 1);
		synt->r_in = 1;
		if (synt->i == synt->len_end)
			synt->error = 1;
	}
	return (0);
}

/*
** Handles output redirection: '>' and '>>' (append)
** 
** Error cases:
** - Consecutive redirections: "> >", "> >>", etc.
** - Redirection at end of line (no filename)
** 
** Returns: 1 if error detected, 0 if valid
*/
static int	st_redir_out(t_syntax **syntax)
{
	t_syntax	*synt;

	synt = *syntax;
	if (synt->current[synt->i + 1] && synt->current[synt->i + 1] == '>')
	{
		if (synt->r_in || synt->r_here || synt->r_out || synt->r_app)
			return (synt->error = 5, 1);
		synt->i++;
		if (synt->i == synt->len_end)
			synt->error = 1;
		synt->r_app = 1;
	}
	else
	{
		if (synt->r_in || synt->r_here || synt->r_out || synt->r_app)
			return (synt->error = 4, 1);
		synt->r_out = 1;
		if (synt->i == synt->len_end)
			synt->error = 1;
	}
	return (0);
}

/*
** Main redirection syntax checker
** Called when we encounter '<' or '>' outside quotes
** 
** Returns: 1 if error detected, 0 if valid
*/
int	ft_redir_syntax(t_syntax **syntax)
{
	t_syntax	*synt;

	synt = *syntax;
	if (synt->current[synt->i] == '<')
	{
		if (st_redir_in(&synt))
			return (1);
	}
	else if (synt->current[synt->i] == '>')
	{
		if (st_redir_out(&synt))
			return (1);
	}
	return (0);
}
