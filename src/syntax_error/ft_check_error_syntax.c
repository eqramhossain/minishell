/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_error_syntax.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehossain <ehossain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 11:39:40 by ehossain          #+#    #+#             */
/*   Updated: 2025/10/25 11:42:49 by ehossain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "syntax.h"

static void	st_print_error_token(int error)
{
	if (error == 1)
		ft_putstr_fd("`newline'\n", 2);
	else if (error == 2)
		ft_putstr_fd("`<'\n", 2);
	else if (error == 3)
		ft_putstr_fd("`<<'\n", 2);
	else if (error == 4)
		ft_putstr_fd("`>'\n", 2);
	else if (error == 5)
		ft_putstr_fd("`>>'\n", 2);
	else if (error == 6)
		ft_putstr_fd("`|'\n", 2);
}

int	ft_check_error_syntax(t_syntax **syntax)
{
	t_syntax	*synt;

	synt = *syntax;
	if (synt->sq_trigger || synt->dq_trigger || synt->error > 0)
	{
		ft_putstr_fd("minishell: syntax error near unexpected token ", 2);
		if (synt->error > 0)
			st_print_error_token(synt->error);
		else if (synt->sq_trigger == 1)
			ft_putstr_fd("`\''\n", 2);
		else if (synt->dq_trigger == 1)
			ft_putstr_fd("`\"'\n", 2);
		return (1);
	}
	return (0);
}
