/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset_builtin.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehossain <ehossain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 11:30:58 by ehossain          #+#    #+#             */
/*   Updated: 2025/10/25 19:33:05 by ehossain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"

static int	is_valid_identifier_unset(char *str)
{
	int	i;

	if (!str || !str[0])
		return (0);
	if (!ft_isalpha(str[0]) && str[0] != '_')
		return (0);
	i = 1;
	while (str[i])
	{
		if (!ft_isalnum(str[i]) && str[i] != '_')
			return (0);
		i++;
	}
	return (1);
}

static void	print_unset_error(char *arg)
{
	ft_putstr_fd("minishell: unset: `", STDERR);
	ft_putstr_fd(arg, STDERR);
	ft_putendl_fd("': not a valid identifier", STDERR);
}

static void	remove_env_node(t_envp **env, char *key)
{
	t_envp	*current;
	t_envp	*prev;

	current = *env;
	prev = NULL;
	while (current)
	{
		if (ft_strncmp(current->key, key, ft_strlen(key) + 1) == 0)
		{
			if (prev)
				prev->next = current->next;
			else
				*env = current->next;
			free(current->key);
			if (current->value)
				free(current->value);
			free(current);
			return ;
		}
		prev = current;
		current = current->next;
	}
}

int	ft_unset(char **args, t_ms_data *ms_data)
{
	int	i;
	int	status;

	if (!args[1])
		return (SUCCESS);
	status = SUCCESS;
	i = 1;
	while (args[i])
	{
		if (!is_valid_identifier_unset(args[i]))
		{
			print_unset_error(args[i]);
			status = ERROR;
		}
		else
			remove_env_node(&ms_data->envp, args[i]);
		i++;
	}
	return (status);
}
