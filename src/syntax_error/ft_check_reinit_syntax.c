/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_reinit_syntax.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekram <ekram@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 16:18:39 by gmarquis          #+#    #+#             */
/*   Updated: 2025/10/22 12:05:26 by ehossain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "syntax.h"

static int	st_reinit_redir(char c)
{
	if (c != ' ' && c != '\t' && c != '|' && c != '<' && c != '>'
		&& ft_isascii(c))
		return (1);
	return (0);
}

static int	st_reinit_pipe(char c)
{
	if (c != ' ' && c != '\t' && c != '|' && ft_isascii(c))
		return (1);
	return (0);
}

int	ft_check_reinit(t_syntax **syntax)
{
	t_syntax	*synt;

	synt = *syntax;
	if (st_reinit_redir(synt->current[synt->i]))
	{
		synt->r_in = 0;
		synt->r_here = 0;
		synt->r_out = 0;
		synt->r_app = 0;
	}
	if (st_reinit_pipe(synt->current[synt->i]))
		synt->pipe_flag = 0;
	if (!synt->dq_trigger && !synt->sq_trigger)
	{
		if (synt->current[synt->i] == '<' || synt->current[synt->i] == '>')
		{
			if (ft_redir_syntax(&synt))
				return (1);
		}
		if (synt->current[synt->i] == '|')
		{
			if (ft_pipe_syntax(&synt))
				return (1);
		}
	}
	return (0);
}
