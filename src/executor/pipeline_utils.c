/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipeline_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekram <ekram@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/25 19:30:00 by ehossain          #+#    #+#             */
/*   Updated: 2025/10/25 19:19:22 by ekram            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "executor.h"
#include "minishell.h"

int	ft_count_commands(t_cmd *cmd)
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

void	ft_setup_pipe_redir(int prev_pipe, int *curr_pipe, int is_last)
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

int	ft_wait_pipeline(pid_t *pids, int count)
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
	free(pids);
	return (exit_status);
}
