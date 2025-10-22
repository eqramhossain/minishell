/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   external_command.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehossain <ehossain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 20:30:00 by ehossain          #+#    #+#             */
/*   Updated: 2025/10/22 20:30:00 by ehossain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "executor.h"

/**
 * Child process: execute the command
 */
static void	child_execute(t_ms_data *ms_data, t_cmd *cmd)
{
	char	*path;
	char	**env_array;

	setup_child_signals();
	if (apply_redirections(cmd->redir) == ERROR)
		exit(1);
	path = find_command_path(cmd->argv[0], ms_data->envp);
	if (!path)
	{
		ft_putstr_fd("minishell: ", STDERR);
		ft_putstr_fd(cmd->argv[0], STDERR);
		ft_putendl_fd(": command not found", STDERR);
		exit(127);
	}
	env_array = envp_to_array(ms_data->envp);
	if (!env_array)
		exit(1);
	execve(path, cmd->argv, env_array);
	ft_putstr_fd("minishell: ", STDERR);
	ft_putstr_fd(cmd->argv[0], STDERR);
	ft_putendl_fd(": cannot execute", STDERR);
	free(path);
	free_array(env_array);
	exit(126);
}

/**
 * Execute external command (single, no pipes)
 */
int	execute_external_single(t_ms_data *ms_data, t_cmd *cmd)
{
	pid_t	pid;
	int		status;
	int		exit_status;

	pid = fork();
	if (pid < 0)
	{
		ft_putendl_fd("minishell: fork failed", STDERR);
		return (ERROR);
	}
	if (pid == 0)
		child_execute(ms_data, cmd);
	waitpid(pid, &status, 0);
	if (WIFEXITED(status))
		exit_status = WEXITSTATUS(status);
	else if (WIFSIGNALED(status))
		exit_status = 128 + WTERMSIG(status);
	else
		exit_status = 1;
	return (exit_status);
}
