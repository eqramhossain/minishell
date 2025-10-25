/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipeline_exec.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekram <ekram@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/25 19:30:00 by ehossain          #+#    #+#             */
/*   Updated: 2025/10/25 19:19:22 by ekram            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "executor.h"
#include "minishell.h"

static void	ft_exec_builtin_in_pipe(t_ms_data *ms_data, t_cmd *cmd)
{
	ms_data->exit_status = ft_execute_builtin(ms_data, cmd->argv);
	ft_free_ms_data(ms_data);
	exit(ms_data->exit_status);
}

static void	ft_exec_cmd_error(t_ms_data *ms_data, char *cmd, int exit_code)
{
	if (exit_code == 127)
	{
		ft_putstr_fd("minishell: ", STDERR);
		ft_putstr_fd(cmd, STDERR);
		ft_putendl_fd(": command not found", STDERR);
	}
	else
	{
		ft_putstr_fd("minishell: cannot execute: ", STDERR);
		ft_putendl_fd(cmd, STDERR);
	}
	ft_free_ms_data(ms_data);
	exit(exit_code);
}

static void	ft_exec_external_cmd(t_ms_data *ms_data, t_cmd *cmd)
{
	char	*path;
	char	**env_array;

	path = ft_find_command_path(cmd->argv[0], ms_data->envp);
	if (!path)
		ft_exec_cmd_error(ms_data, cmd->argv[0], 127);
	env_array = ft_envp_to_array(ms_data->envp);
	if (!env_array)
	{
		free(path);
		ft_free_ms_data(ms_data);
		exit(1);
	}
	execve(path, cmd->argv, env_array);
	free(path);
	ft_free_array(env_array);
	ft_exec_cmd_error(ms_data, cmd->argv[0], 126);
}

void	ft_execute_pipe_child(t_ms_data *ms_data, t_cmd *cmd, t_pipe_data *p)
{
	ft_setup_child_signals();
	ft_setup_pipe_redir(p->prev_pipe, p->curr_pipe, p->is_last);
	if (ft_apply_redirections(cmd->redir) == ERROR)
	{
		ft_free_ms_data(ms_data);
		exit(1);
	}
	if (ft_is_builtin(cmd->argv[0]) == SUCCESS)
		ft_exec_builtin_in_pipe(ms_data, cmd);
	ft_exec_external_cmd(ms_data, cmd);
}
