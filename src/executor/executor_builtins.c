/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor_builtins.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehossain <ehossain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 19:39:18 by ehossain          #+#    #+#             */
/*   Updated: 2025/10/22 19:49:10 by ehossain         ###   ########.fr       */
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

// int	ft_executor_builtins(t_ms_data *ms_data)
// {
// 	int	result;
//
// 	result = 0;
// 	if (ft_strcmp(args[0], "echo") == 0)
// 		result = ft_echo(args);
// 	if (ft_strcmp(args[0], "cd") == 0)
// 		result = ft_cd(args, mini->env);
// 	if (ft_strcmp(args[0], "pwd") == 0)
// 		result = ft_pwd();
// 	if (ft_strcmp(args[0], "env") == 0)
// 		ft_envp(mini->env);
// 	if (ft_strcmp(args[0], "export") == 0)
// 		ft_export(args, mini->env, mini->secret_env);
// 	if (ft_strcmp(args[0], "unset") == 0)
// 		ft_unset(args, mini);
// 	return (result);
// }
