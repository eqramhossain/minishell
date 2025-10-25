/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_builtin.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehossain <ehossain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 11:30:41 by ehossain          #+#    #+#             */
/*   Updated: 2025/10/25 19:26:25 by ehossain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"

static t_envp	*find_env_var(t_envp *env, char *key)
{
	t_envp	*current;

	current = env;
	while (current)
	{
		if (ft_strncmp(current->key, key, ft_strlen(key) + 1) == 0)
			return (current);
		current = current->next;
	}
	return (NULL);
}

static void	update_or_add_env(t_envp **env, char *key, char *value)
{
	t_envp	*current;
	t_envp	*new_node;

	current = find_env_var(*env, key);
	if (current)
	{
		if (value && current->value)
			free(current->value);
		if (value)
			current->value = ft_strdup(value);
		return ;
	}
	new_node = malloc(sizeof(t_envp));
	new_node->key = ft_strdup(key);
	if (value)
		new_node->value = ft_strdup(value);
	else
		new_node->value = NULL;
	new_node->next = NULL;
	if (*env)
		ft_envadd_back(env, new_node);
	else
		*env = new_node;
}

static int	process_export_arg(char *arg, t_ms_data *ms_data)
{
	char	*equal_sign;
	char	*key;
	char	*value;
	int		key_len;

	equal_sign = ft_strchr(arg, '=');
	if (equal_sign)
	{
		key_len = equal_sign - arg;
		key = ft_substr(arg, 0, key_len);
		value = ft_strdup(equal_sign + 1);
	}
	else
	{
		key = ft_strdup(arg);
		value = NULL;
	}
	if (!is_valid_identifier(key))
	{
		print_export_error(arg);
		free(key);
		if (value)
			free(value);
		return (ERROR);
	}
	update_or_add_env(&ms_data->envp, key, value);
	free(key);
	if (value)
		free(value);
	return (SUCCESS);
}

int	ft_export(char **args, t_ms_data *ms_data)
{
	int	i;
	int	status;

	if (!args[1])
	{
		print_sorted_env(ms_data->envp);
		return (SUCCESS);
	}
	status = SUCCESS;
	i = 1;
	while (args[i])
	{
		if (process_export_arg(args[i], ms_data) == ERROR)
			status = ERROR;
		i++;
	}
	return (status);
}
