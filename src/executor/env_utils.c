/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehossain <ehossain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 20:30:00 by ehossain          #+#    #+#             */
/*   Updated: 2025/10/22 20:30:00 by ehossain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "executor.h"

/**
 * Count environment variables
 */
static int	count_env_vars(t_envp *env)
{
	int		count;
	t_envp	*current;

	count = 0;
	current = env;
	while (current)
	{
		count++;
		current = current->next;
	}
	return (count);
}

/**
 * Create "KEY=VALUE" string from environment node
 */
static char	*create_env_string(t_envp *node)
{
	char	*temp;
	char	*result;

	temp = ft_strjoin(node->key, "=");
	if (!temp)
		return (NULL);
	result = ft_strjoin(temp, node->value);
	free(temp);
	return (result);
}

/**
 * Convert environment linked list to array for execve
 */
char	**envp_to_array(t_envp *env)
{
	char	**array;
	t_envp	*current;
	int		i;
	int		count;

	count = count_env_vars(env);
	array = malloc(sizeof(char *) * (count + 1));
	if (!array)
		return (NULL);
	current = env;
	i = 0;
	while (current)
	{
		array[i] = create_env_string(current);
		if (!array[i])
		{
			free_array(array);
			return (NULL);
		}
		current = current->next;
		i++;
	}
	array[i] = NULL;
	return (array);
}

/**
 * Free string array
 */
void	free_array(char **array)
{
	int	i;

	if (!array)
		return ;
	i = 0;
	while (array[i])
	{
		free(array[i]);
		i++;
	}
	free(array);
}
