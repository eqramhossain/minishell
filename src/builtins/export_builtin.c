/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_builtin.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehossain <ehossain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 11:30:41 by ehossain          #+#    #+#             */
/*   Updated: 2025/10/25 12:55:54 by ehossain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"

static int	is_valid_identifier(char *str)
{
	int	i;

	if (!str || !str[0])
		return (0);
	if (!ft_isalpha(str[0]) && str[0] != '_')
		return (0);
	i = 1;
	while (str[i] && str[i] != '=')
	{
		if (!ft_isalnum(str[i]) && str[i] != '_')
			return (0);
		i++;
	}
	return (1);
}

static void	print_export_error(char *arg)
{
	ft_putstr_fd("minishell: export: `", STDERR);
	ft_putstr_fd(arg, STDERR);
	ft_putendl_fd("': not a valid identifier", STDERR);
}

static void	print_sorted_env(t_envp *env)
{
	t_envp	*current;

	current = env;
	while (current)
	{
		ft_putstr_fd("declare -x ", STDOUT);
		ft_putstr_fd(current->key, STDOUT);
		if (current->value)
		{
			ft_putstr_fd("=\"", STDOUT);
			ft_putstr_fd(current->value, STDOUT);
			ft_putstr_fd("\"", STDOUT);
		}
		ft_putstr_fd("\n", STDOUT);
		current = current->next;
	}
}

static void	update_or_add_env(t_envp **env, char *key, char *value)
{
	t_envp	*current;
	t_envp	*new_node;

	current = *env;
	while (current)
	{
		if (ft_strncmp(current->key, key, ft_strlen(key) + 1) == 0)
		{
			if (value)
			{
				if (current->value)
					free(current->value);
				current->value = ft_strdup(value);
			}
			return ;
		}
		if (!current->next)
			break ;
		current = current->next;
	}
	new_node = malloc(sizeof(t_envp));
	new_node->key = ft_strdup(key);
	new_node->value = value ? ft_strdup(value) : NULL;
	new_node->next = NULL;
	if (current)
		current->next = new_node;
	else
		*env = new_node;
}

static int	export_variable(char *arg, t_ms_data *ms_data)
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
		if (export_variable(args[i], ms_data) == ERROR)
			status = ERROR;
		i++;
	}
	return (status);
}
