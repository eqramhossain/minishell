/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_quote.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehossain <ehossain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/25 14:12:39 by ehossain          #+#    #+#             */
/*   Updated: 2025/10/25 14:13:43 by ehossain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "quote.h"

int	ft_process_quotes_cmd(t_cmd *cmd)
{
	char	**new_argv;
	int		i;

	if (!cmd || !cmd->argv)
		return (SUCCESS);
	new_argv = ft_remove_quotes_array(cmd->argv);
	if (!new_argv)
		return (ERROR);
	i = 0;
	while (cmd->argv[i])
	{
		free(cmd->argv[i]);
		i++;
	}
	free(cmd->argv);
	cmd->argv = new_argv;
	return (SUCCESS);
}

int	ft_process_quotes_pipeline(t_cmd *cmd_list)
{
	t_cmd	*current;

	current = cmd_list;
	while (current)
	{
		if (ft_process_quotes_cmd(current) == ERROR)
			return (ERROR);
		current = current->next;
	}
	return (SUCCESS);
}

int	ft_process_quotes_redir(t_redir *redir)
{
	char	*new_file;
	t_redir	*current;

	current = redir;
	while (current)
	{
		if (current->file)
		{
			new_file = ft_remove_quotes(current->file);
			if (!new_file)
				return (ERROR);
			free(current->file);
			current->file = new_file;
		}
		current = current->next;
	}
	return (SUCCESS);
}

int	ft_process_quotes_full(t_cmd *cmd_list)
{
	t_cmd	*current;

	current = cmd_list;
	while (current)
	{
		if (ft_process_quotes_cmd(current) == ERROR)
			return (ERROR);
		if (ft_process_quotes_redir(current->redir) == ERROR)
			return (ERROR);
		current = current->next;
	}
	return (SUCCESS);
}
