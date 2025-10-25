/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipeline.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekram <ekram@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 11:28:58 by ehossain          #+#    #+#             */
/*   Updated: 2025/10/25 19:19:22 by ekram            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "executor.h"
#include "minishell.h"

static void	ft_close_pipes(t_pipe_data *p)
{
	if (p->prev_pipe != -1)
		close(p->prev_pipe);
	if (!p->is_last)
	{
		close(p->curr_pipe[1]);
		p->prev_pipe = p->curr_pipe[0];
	}
}

static pid_t	ft_fork_pipe_cmd(t_ms_data *ms_data, t_cmd *cmd, t_pipe_data *p)
{
	pid_t	pid;

	pid = fork();
	if (pid < 0)
	{
		ft_putendl_fd("minishell: fork failed", STDERR);
		return (-1);
	}
	if (pid == 0)
		ft_execute_pipe_child(ms_data, cmd, p);
	ft_close_pipes(p);
	return (pid);
}

static int	ft_pipe_loop(t_ms_data *ms_data, t_cmd *cmd_list, t_loop_data *l)
{
	t_pipe_data	p;

	l->current = cmd_list;
	l->i = 0;
	while (l->current)
	{
		p.prev_pipe = l->prev_pipe;
		p.is_last = (l->current->next == NULL);
		if (l->current->next && pipe(p.curr_pipe) < 0)
		{
			ft_putendl_fd("minishell: pipe failed", STDERR);
			if (l->prev_pipe != -1)
				close(l->prev_pipe);
			free(l->pids);
			return (ERROR);
		}
		l->pids[l->i] = ft_fork_pipe_cmd(ms_data, l->current, &p);
		if (l->pids[l->i] < 0)
			return (ERROR);
		l->prev_pipe = p.prev_pipe;
		l->current = l->current->next;
		l->i++;
	}
	return (SUCCESS);
}

int	ft_execute_pipeline(t_ms_data *ms_data, t_cmd *cmd_list)
{
	t_loop_data	l;
	int			count;

	count = ft_count_commands(cmd_list);
	l.pids = malloc(sizeof(pid_t) * count);
	if (!l.pids)
		return (ERROR);
	l.prev_pipe = -1;
	if (ft_pipe_loop(ms_data, cmd_list, &l) == ERROR)
	{
		free(l.pids);
		return (ERROR);
	}
	return (ft_wait_pipeline(l.pids, count));
}
