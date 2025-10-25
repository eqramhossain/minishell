/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_quote_syntax.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehossain <ehossain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 11:40:09 by ehossain          #+#    #+#             */
/*   Updated: 2025/10/25 11:43:17 by ehossain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "syntax.h"

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
