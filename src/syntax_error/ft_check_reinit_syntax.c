/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_reinit_syntax.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehossain <ehossain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 11:39:48 by ehossain          #+#    #+#             */
/*   Updated: 2025/10/25 17:32:43 by ehossain         ###   ########.fr       */
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

static int	ft_handle_special_chars(t_syntax *synt)
{
	if ((synt->current[synt->i] == '<' || synt->current[synt->i] == '>')
		&& ft_redir_syntax(&synt))
		return (1);
	if (synt->current[synt->i] == '|' && ft_pipe_syntax(&synt))
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
		return (ft_handle_special_chars(synt));
	return (0);
}
