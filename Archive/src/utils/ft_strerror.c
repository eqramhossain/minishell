/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strerror.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehossain <ehossain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/19 15:31:43 by ehossain          #+#    #+#             */
/*   Updated: 2025/07/19 15:33:27 by ehossain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_strerror(char *str)
{
	if (!str)
		return ;
	else
	{
		ft_putstr_fd(str, 2);
		ft_putchar_fd('\n', 2);
	}
}
