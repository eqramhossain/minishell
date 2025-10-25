/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ms_syntax_error.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehossain <ehossain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 11:39:55 by ehossain          #+#    #+#             */
/*   Updated: 2025/10/25 11:43:00 by ehossain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "syntax.h"

static int	st_line_check(t_syntax *synt)
{
	while (synt->current[synt->i])
	{
		if (ft_check_reinit(&synt))
			break ;
		ft_quote_syntax(&synt);
		synt->i++;
	}
	return (ft_check_error_syntax(&synt));
}

int	ft_ms_syntax_error(const char *input)
{
	t_syntax	synt;
	int			error;

	ft_memset(&synt, 0, sizeof(t_syntax));
	synt.current = ft_strtrim((char *)input, " \t");
	if (!synt.current)
		return (0);
	if (synt.current[0] == '\0')
		return (free(synt.current), 0);
	synt.len_end = ft_strlen(synt.current) - 1;
	error = st_line_check(&synt);
	free(synt.current);
	return (error);
}
