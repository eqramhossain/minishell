/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expansion.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehossain <ehossain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 22:43:56 by ehossain          #+#    #+#             */
/*   Updated: 2025/10/24 22:43:57 by ehossain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "environment.h"

static void	ft_expand_cmd_args(t_cmd *cmd, t_envp *env, int exit_status);
static void	ft_expand_redirections(t_cmd *cmd, t_envp *env, int exit_status);

void	ft_expand_variables(t_ms_data *data)
{
	t_cmd	*current_cmd;

	current_cmd = data->parser->cmds;
	while (current_cmd)
	{
		ft_expand_cmd_args(current_cmd, data->envp, data->exit_status);
		ft_expand_redirections(current_cmd, data->envp, data->exit_status);
		current_cmd = current_cmd->next;
	}
}

static void	ft_expand_cmd_args(t_cmd *cmd, t_envp *env, int exit_status)
{
	int		i;
	char	*expanded;
	char	*old;

	if (!cmd || !cmd->argv)
		return ;
	i = 0;
	while (cmd->argv[i])
	{
		old = cmd->argv[i];
		expanded = ft_expand_string(old, env, exit_status);
		if (expanded)
		{
			cmd->argv[i] = expanded;
			free(old);
		}
		i++;
	}
}

static void	ft_expand_redirections(t_cmd *cmd, t_envp *env, int exit_status)
{
	t_redir	*current_redir;
	char	*expanded;
	char	*old;

	if (!cmd)
		return ;
	current_redir = cmd->redir;
	while (current_redir)
	{
		if (current_redir->file)
		{
			old = current_redir->file;
			expanded = ft_expand_string(old, env, exit_status);
			if (expanded)
			{
				current_redir->file = expanded;
				free(old);
			}
		}
		current_redir = current_redir->next;
	}
}
