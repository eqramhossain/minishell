/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd_builtin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehossain <ehossain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 11:30:10 by ehossain          #+#    #+#             */
/*   Updated: 2025/10/25 12:53:17 by ehossain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"

static char	*get_env_value_by_key(t_envp *env, char *key)
{
	t_envp	*current;

	current = env;
	while (current)
	{
		if (ft_strncmp(current->key, key, ft_strlen(key) + 1) == 0)
			return (current->value);
		current = current->next;
	}
	return (NULL);
}

static void	update_env_value(t_envp *env, char *key, char *new_value)
{
	t_envp	*current;

	current = env;
	while (current)
	{
		if (ft_strncmp(current->key, key, ft_strlen(key) + 1) == 0)
		{
			if (current->value)
				free(current->value);
			current->value = ft_strdup(new_value);
			return ;
		}
		current = current->next;
	}
}

static int	change_directory(char *path, t_ms_data *ms_data)
{
	char	oldpwd[PATH_MAX];
	char	newpwd[PATH_MAX];

	if (!getcwd(oldpwd, PATH_MAX))
		return (ERROR);
	if (chdir(path) != 0)
	{
		ft_putstr_fd("minishell: cd: ", STDERR);
		ft_putstr_fd(path, STDERR);
		ft_putstr_fd(": ", STDERR);
		ft_putendl_fd(strerror(errno), STDERR);
		return (ERROR);
	}
	if (!getcwd(newpwd, PATH_MAX))
		return (ERROR);
	update_env_value(ms_data->envp, "OLDPWD", oldpwd);
	update_env_value(ms_data->envp, "PWD", newpwd);
	return (SUCCESS);
}

int	ft_cd(char **args, t_ms_data *ms_data)
{
	char	*path;

	if (!args[1])
	{
		path = get_env_value_by_key(ms_data->envp, "HOME");
		if (!path)
		{
			ft_putendl_fd("minishell: cd: HOME not set", STDERR);
			return (ERROR);
		}
	}
	else if (args[2])
	{
		ft_putendl_fd("minishell: cd: too many arguments", STDERR);
		return (ERROR);
	}
	else
		path = args[1];
	return (change_directory(path, ms_data));
}
