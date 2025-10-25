/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_string.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehossain <ehossain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 22:43:46 by ehossain          #+#    #+#             */
/*   Updated: 2025/10/25 00:13:35 by ehossain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "environment.h"

static char	*ft_get_variable_value(char *str, int *i, t_envp *env,
				int exit_status);
static char	*ft_append_to_result(char *result, char *to_add);

char	*ft_expand_string(char *str, t_envp *env, int exit_status)
{
	char	*result;
	char	*temp;
	char	*value;
	int		i;

	if (!str)
		return (NULL);
	result = ft_strdup("");
	if (!result)
		return (NULL);
	i = 0;
	while (str[i])
	{
		if (str[i] == '$' && (str[i + 1] == '?' || ft_is_var_char(str[i + 1])))
		{
			i++;
			value = ft_get_variable_value(str, &i, env, exit_status);
			temp = ft_append_to_result(result, value);
			free(value);
			free(result);
			result = temp;
		}
		else
		{
			temp = ft_calloc(2, sizeof(char));
			if (!temp)
			{
				free(result);
				return (NULL);
			}
			temp[0] = str[i];
			temp[1] = '\0';
			value = ft_append_to_result(result, temp);
			free(temp);
			free(result);
			result = value;
			i++;
		}
	}
	return (result);
}

static char	*ft_get_variable_value(char *str, int *i, t_envp *env,
		int exit_status)
{
	char	*var_name;
	char	*value;
	int		len;
	int		j;

	if (str[*i] == '?')
	{
		(*i)++;
		return (ft_itoa(exit_status));
	}
	len = ft_get_var_name_len(&str[*i]);
	var_name = ft_calloc(len + 1, sizeof(char));
	if (!var_name)
		return (ft_strdup(""));
	j = 0;
	while (j < len)
	{
		var_name[j] = str[*i];
		(*i)++;
		j++;
	}
	var_name[j] = '\0';
	value = ft_get_env_value(var_name, env);
	free(var_name);
	if (!value)
		return (ft_strdup(""));
	return (ft_strdup(value));
}

static char	*ft_append_to_result(char *result, char *to_add)
{
	char	*new_result;

	if (!to_add)
		return (result);
	new_result = ft_strjoin(result, to_add);
	return (new_result);
}
