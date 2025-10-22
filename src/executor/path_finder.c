/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_finder.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehossain <ehossain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 20:30:00 by ehossain          #+#    #+#             */
/*   Updated: 2025/10/22 20:30:00 by ehossain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "executor.h"

/**
 * Get PATH value from environment
 */
static char	*get_path_from_env(t_envp *env)
{
	t_envp	*current;

	current = env;
	while (current)
	{
		if (ft_strcmp(current->key, "PATH") == 0)
			return (current->value);
		current = current->next;
	}
	return (NULL);
}

/**
 * Join directory and command with '/'
 */
static char	*join_path(char *dir, char *cmd)
{
	char	*temp;
	char	*result;

	temp = ft_strjoin(dir, "/");
	if (!temp)
		return (NULL);
	result = ft_strjoin(temp, cmd);
	free(temp);
	return (result);
}

/**
 * Search command in PATH directories
 */
static char	*search_in_path(char **paths, char *command)
{
	int		i;
	char	*full_path;

	i = 0;
	while (paths[i])
	{
		full_path = join_path(paths[i], command);
		if (!full_path)
			return (NULL);
		if (access(full_path, X_OK) == 0)
			return (full_path);
		free(full_path);
		i++;
	}
	return (NULL);
}

/**
 * Find the executable path for a command
 * Returns allocated string or NULL if not found
 */
char	*find_command_path(char *command, t_envp *env)
{
	char	*path_env;
	char	**paths;
	char	*result;

	if (!command || !command[0])
		return (NULL);
	if (ft_strchr(command, '/'))
	{
		if (access(command, X_OK) == 0)
			return (ft_strdup(command));
		return (NULL);
	}
	path_env = get_path_from_env(env);
	if (!path_env)
		return (NULL);
	paths = ft_split(path_env, ':');
	if (!paths)
		return (NULL);
	result = search_in_path(paths, command);
	free_array(paths);
	return (result);
}
