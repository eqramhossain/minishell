/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor_builtins.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehossain <ehossain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 11:29:20 by ehossain          #+#    #+#             */
/*   Updated: 2025/10/23 11:29:22 by ehossain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "executor.h"

int	ft_is_builtin(char *cmd)
{
	if (ft_strcmp(cmd, "echo") == 0)
		return (SUCCESS);
	if (ft_strcmp(cmd, "cd") == 0)
		return (SUCCESS);
	if (ft_strcmp(cmd, "pwd") == 0)
		return (SUCCESS);
	if (ft_strcmp(cmd, "env") == 0)
		return (SUCCESS);
	if (ft_strcmp(cmd, "export") == 0)
		return (SUCCESS);
	if (ft_strcmp(cmd, "unset") == 0)
		return (SUCCESS);
	return (ERROR);
}

int	ft_execute_builtin(t_ms_data *ms_data, char **argv)
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
