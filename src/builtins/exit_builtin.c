/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_builtin.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehossain <ehossain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 11:30:34 by ehossain          #+#    #+#             */
/*   Updated: 2025/10/24 11:51:43 by ehossain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"

// TODO: Implement this properly with exit code handling!

int	ft_exit(char **args, t_ms_data *ms_data)
{
	int	exit_code;

	exit_code = 0;
	ft_putendl_fd("exit", STDOUT);
	if (args[1])
	{
		exit_code = ft_atoi(args[1]);
	}
	else
	{
		exit_code = ms_data->exit_status;
	}
	exit(exit_code);
	return (0);
}
