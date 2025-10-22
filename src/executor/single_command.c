/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   single_command.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehossain <ehossain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 20:30:00 by ehossain          #+#    #+#             */
/*   Updated: 2025/10/22 20:30:00 by ehossain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "executor.h"

/**
 * Execute a builtin command in the parent process
 * We do this in parent so changes affect the shell (like cd)
 */
static int	execute_builtin_parent(t_ms_data *ms_data, t_cmd *cmd)
{
	int	saved_stdin;
	int	saved_stdout;
	int	exit_status;

	saved_stdin = dup(STDIN);
	saved_stdout = dup(STDOUT);
	if (apply_redirections(cmd->redir) == ERROR)
	{
		dup2(saved_stdin, STDIN);
		dup2(saved_stdout, STDOUT);
		close(saved_stdin);
		close(saved_stdout);
		return (ERROR);
	}
	exit_status = execute_builtin(ms_data, cmd->argv);
	dup2(saved_stdin, STDIN);
	dup2(saved_stdout, STDOUT);
	close(saved_stdin);
	close(saved_stdout);
	return (exit_status);
}

/**
 * Execute a single command (no pipes)
 */
int	execute_single_command(t_ms_data *ms_data, t_cmd *cmd)
{
	if (!cmd || !cmd->argv || !cmd->argv[0])
		return (SUCCESS);
	if (ft_is_builtin(cmd->argv[0]) == SUCCESS)
		return (execute_builtin_parent(ms_data, cmd));
	else
		return (execute_external_single(ms_data, cmd));
}
