/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_executor.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehossain <ehossain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 20:30:00 by ehossain          #+#    #+#             */
/*   Updated: 2025/10/22 20:30:00 by ehossain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "executor.h"

/**
 * Execute a builtin command and return its exit status
 */
int	execute_builtin(t_ms_data *ms_data, char **argv)
{
	if (ft_strcmp(argv[0], "echo") == 0)
		return (ft_echo(argv));
	if (ft_strcmp(argv[0], "cd") == 0)
		return (ft_cd(argv, ms_data));
	if (ft_strcmp(argv[0], "pwd") == 0)
		return (ft_pwd());
	if (ft_strcmp(argv[0], "env") == 0)
		return (ft_envp(ms_data->envp));
	if (ft_strcmp(argv[0], "export") == 0)
		return (ft_export(argv, ms_data));
	if (ft_strcmp(argv[0], "unset") == 0)
		return (ft_unset(argv, ms_data));
	if (ft_strcmp(argv[0], "exit") == 0)
		return (ft_exit(argv, ms_data));
	return (ERROR);
}
