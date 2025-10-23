/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   single_command.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehossain <ehossain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 11:29:31 by ehossain          #+#    #+#             */
/*   Updated: 2025/10/23 11:29:34 by ehossain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "executor.h"

static int	ft_execute_builtin_parent(t_ms_data *ms_data, t_cmd *cmd)
{
	int	saved_stdin;
	int	saved_stdout;
	int	exit_status;

	saved_stdin = dup(STDIN);
	saved_stdout = dup(STDOUT);
	if (ft_apply_redirections(cmd->redir) == ERROR)
	{
		dup2(saved_stdin, STDIN);
		dup2(saved_stdout, STDOUT);
		close(saved_stdin);
		close(saved_stdout);
		return (ERROR);
	}
	exit_status = ft_execute_builtin(ms_data, cmd->argv);
	dup2(saved_stdin, STDIN);
	dup2(saved_stdout, STDOUT);
	close(saved_stdin);
	close(saved_stdout);
	return (exit_status);
}

int	ft_execute_single_command(t_ms_data *ms_data, t_cmd *cmd)
{
	if (!cmd || !cmd->argv || !cmd->argv[0])
		return (SUCCESS);
	if (ft_is_builtin(cmd->argv[0]) == SUCCESS)
		return (ft_execute_builtin_parent(ms_data, cmd));
	else
		return (ft_execute_external_single(ms_data, cmd));
}
