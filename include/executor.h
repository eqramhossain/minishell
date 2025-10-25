/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekram <ekram@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 22:03:21 by ehossain          #+#    #+#             */
/*   Updated: 2025/10/25 19:19:23 by ekram            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTOR_H
# define EXECUTOR_H

# include "builtins.h"
# include "environment.h"
# include "signals.h"
# include "structures_def.h"

typedef struct s_pipe_data
{
	int	prev_pipe;
	int	curr_pipe[2];
	int	is_last;
}	t_pipe_data;

typedef struct s_loop_data
{
	pid_t	*pids;
	int		prev_pipe;
	t_cmd	*current;
	int		i;
}	t_loop_data;

int		ft_executor(t_ms_data *ms_data);

int		ft_execute_single_command(t_ms_data *ms_data, t_cmd *cmd);
int		ft_execute_external_single(t_ms_data *ms_data, t_cmd *cmd);
int		ft_execute_pipeline(t_ms_data *ms_data, t_cmd *cmd_list);

int		ft_is_builtin(char *cmd);
int		ft_execute_builtin(t_ms_data *ms_data, char **argv);

char	*ft_find_command_path(char *command, t_envp *env);
int		ft_apply_redirections(t_redir *redir_list);

int		ft_count_commands(t_cmd *cmd);
void	ft_setup_pipe_redir(int prev_pipe, int *curr_pipe, int is_last);
int		ft_wait_pipeline(pid_t *pids, int count);
void	ft_execute_pipe_child(t_ms_data *ms_data, t_cmd *cmd, t_pipe_data *p);

#endif
