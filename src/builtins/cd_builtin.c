/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd_builtin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehossain <ehossain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 11:30:10 by ehossain          #+#    #+#             */
/*   Updated: 2025/10/23 11:30:13 by ehossain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"

// TODO: Implement this properly!

int	ft_cd(char **args, t_ms_data *ms_data)
{
	(void)ms_data;
	if (!args[1])
	{
		ft_putendl_fd("cd: missing argument", STDERR);
		return (1);
	}
	if (chdir(args[1]) != 0)
	{
		ft_putstr_fd("cd: ", STDERR);
		ft_putstr_fd(args[1], STDERR);
		ft_putendl_fd(": No such file or directory", STDERR);
		return (1);
	}
	return (0);
}
