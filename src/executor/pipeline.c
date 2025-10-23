/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipeline.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehossain <ehossain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 11:28:58 by ehossain          #+#    #+#             */
/*   Updated: 2025/10/23 11:29:00 by ehossain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "executor.h"

static int	count_commands(t_cmd *cmd)
{
	int		count;
	t_cmd	*current;

	count = 0;
	current = cmd;
	while (current)
	{
		count++;
		current = current->next;
	}
	return (count);
}

static void	setup_pipe_redirection(int prev_pipe, int *curr_pipe, int is_last)
{
	if (prev_pipe != -1)
	{
		dup2(prev_pipe, STDIN);
		close(prev_pipe);
	}
	if (!is_last)
	{
		dup2(curr_pipe[1], STDOUT);
		close(curr_pipe[0]);
		close(curr_pipe[1]);
	}
}

static void	execute_pipeline_child(t_ms_data *ms_data, t_cmd *cmd,
		int prev_pipe, int *curr_pipe, int is_last)
{
	char	*path;
	char	**env_array;

	ft_setup_child_signals();
	setup_pipe_redirection(prev_pipe, curr_pipe, is_last);
	if (ft_apply_redirections(cmd->redir) == ERROR)
		exit(1);
	if (ft_is_builtin(cmd->argv[0]) == SUCCESS)
		exit(ft_execute_builtin(ms_data, cmd->argv));
	path = ft_find_command_path(cmd->argv[0], ms_data->envp);
	if (!path)
	{
		ft_putstr_fd("minishell: ", STDERR);
		ft_putstr_fd(cmd->argv[0], STDERR);
		ft_putendl_fd(": command not found", STDERR);
		exit(127);
	}
	env_array = ft_envp_to_array(ms_data->envp);
	execve(path, cmd->argv, env_array);
	ft_putstr_fd("minishell: cannot execute: ", STDERR);
	ft_putendl_fd(cmd->argv[0], STDERR);
	exit(126);
}

static pid_t	fork_pipeline_command(t_ms_data *ms_data, t_cmd *cmd,
		int *prev_pipe, int curr_pipe[2], int is_last)
{
	pid_t	pid;

	pid = fork();
	if (pid < 0)
	{
		ft_putendl_fd("minishell: fork failed", STDERR);
		return (-1);
	}
	if (pid == 0)
		execute_pipeline_child(ms_data, cmd, *prev_pipe, curr_pipe, is_last);
	if (*prev_pipe != -1)
		close(*prev_pipe);
	if (!is_last)
	{
		close(curr_pipe[1]);
		*prev_pipe = curr_pipe[0];
	}
	return (pid);
}

/**
 * Wait for all pipeline children and get final exit status
 */
static int	wait_pipeline(pid_t *pids, int count)
{
	int	i;
	int	status;
	int	exit_status;

	i = 0;
	exit_status = 0;
	while (i < count)
	{
		waitpid(pids[i], &status, 0);
		if (i == count - 1)
		{
			if (WIFEXITED(status))
				exit_status = WEXITSTATUS(status);
			else if (WIFSIGNALED(status))
				exit_status = 128 + WTERMSIG(status);
		}
		i++;
	}
	return (exit_status);
}

int	ft_execute_pipeline(t_ms_data *ms_data, t_cmd *cmd_list)
{
	pid_t	*pids;
	int		prev_pipe;
	int		curr_pipe[2];
	int		i;
	t_cmd	*current;
	int		count;

	count = count_commands(cmd_list);
	pids = malloc(sizeof(pid_t) * count);
	if (!pids)
		return (ERROR);
	prev_pipe = -1;
	current = cmd_list;
	i = 0;
	while (current)
	{
		if (current->next && pipe(curr_pipe) < 0)
		{
			ft_putendl_fd("minishell: pipe failed", STDERR);
			free(pids);
			return (ERROR);
		}
		pids[i] = fork_pipeline_command(ms_data, current, &prev_pipe, curr_pipe,
				current->next == NULL);
		if (pids[i] < 0)
		{
			free(pids);
			return (ERROR);
		}
		current = current->next;
		i++;
	}
	return (wait_pipeline(pids, count));
}
