/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipe_syntax.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehossain <ehossain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 11:40:02 by ehossain          #+#    #+#             */
/*   Updated: 2025/10/25 11:43:10 by ehossain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "syntax.h"

int	ft_pipe_syntax(t_syntax **syntax)
{
	t_syntax	*synt;

	synt = *syntax;
	if (synt->current[synt->i] != '|')
		return (0);
	if (synt->current[synt->i + 1] && synt->current[synt->i + 1] == '|')
	{
		synt->error = 6;
		return (1);
	}
	if (synt->r_in || synt->r_here || synt->r_out || synt->r_app
		|| synt->pipe_flag)
	{
		synt->error = 6;
		return (1);
	}
	if (synt->i == 0 || synt->i == synt->len_end)
	{
		synt->error = 6;
		return (1);
	}
	synt->pipe_flag = 1;
	return (0);
}
