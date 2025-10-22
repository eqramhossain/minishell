/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehossain <ehossain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 21:39:12 by ehossain          #+#    #+#             */
/*   Updated: 2025/10/22 21:40:00 by ehossain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "executor.h"

/**
 * Count how many commands are in the pipeline
 * Example: "ls | grep a | wc" has 3 commands
 */
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

/**
 * Main executor function
 * This is where execution starts!
 */
int	ft_executor(t_ms_data *ms_data)
{
	t_cmd	*cmd;
	int		cmd_count;
	int		exit_status;

	if (!ms_data || !ms_data->parser || !ms_data->parser->cmds)
		return (ERROR);
	cmd = ms_data->parser->cmds;
	cmd_count = count_commands(cmd);
	if (cmd_count == 1)
		exit_status = execute_single_command(ms_data, cmd);
	else
		exit_status = execute_pipeline(ms_data, cmd);
	ms_data->exit_status = exit_status;
	return (exit_status);
}
