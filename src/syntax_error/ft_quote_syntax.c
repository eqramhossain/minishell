/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_quote_syntax.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehossain <ehossain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 11:40:09 by ehossain          #+#    #+#             */
/*   Updated: 2025/10/23 11:40:10 by ehossain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "syntax.h"

/*
** Quote syntax tracker - manages quote state machine
**
** HOW IT WORKS:
** - When we hit a quote character (' or "), we toggle its trigger
** - sq_trigger tracks single quotes: 0 = outside, 1 = inside
** - dq_trigger tracks double quotes: 0 = outside, 1 = inside
**
** RULES:
** - Single quotes can't be opened inside double quotes (and vice versa)
** - If we reach end of string with a trigger still = 1, it's unclosed
**
** Example: echo "hello world"
** - See first ", set dq_trigger = 1, return 1 (skip other checks)
** - Process characters inside quotes
** - See second ", set dq_trigger = 0, return 1
**
** Returns: 1 if quote character was processed, 0 if not a quote
*/
int	ft_quote_syntax(t_syntax **syntax)
{
	t_syntax	*synt;

	synt = *syntax;
	if (synt->current[synt->i] == '\'' && synt->sq_trigger)
	{
		synt->sq_trigger = 0;
		return (1);
	}
	else if (synt->current[synt->i] == '\"' && synt->dq_trigger)
	{
		synt->dq_trigger = 0;
		return (1);
	}
	else if (synt->current[synt->i] == '\'' && !synt->dq_trigger)
	{
		synt->sq_trigger = 1;
		return (1);
	}
	else if (synt->current[synt->i] == '\"' && !synt->sq_trigger)
	{
		synt->dq_trigger = 1;
		return (1);
	}
	return (0);
}
