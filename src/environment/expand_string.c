/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_string_new.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekram <ekram@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/25 17:50:59 by ehossain          #+#    #+#             */
/*   Updated: 2025/10/25 18:17:45 by ekram            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "environment.h"
#include "tokenizer.h"

static char	*ft_append_single_char(char *result, char c)
{
	char	*temp;
	char	*new_result;

	temp = ft_calloc(2, sizeof(char));
	if (!temp)
	{
		free(result);
		return (NULL);
	}
	temp[0] = c;
	temp[1] = '\0';
	new_result = ft_append_to_result(result, temp);
	free(temp);
	free(result);
	return (new_result);
}

static char	*ft_handle_variable_expansion(char *str, int *i, char *result,
		t_expansion_data *data)
{
	char	*value;
	char	*temp;

	(*i)++;
	value = ft_get_variable_value(str, i, data->env, data->exit_status);
	temp = ft_append_to_result(result, value);
	free(value);
	free(result);
	return (temp);
}

char	*ft_expand_string(char *str, t_envp *env, int exit_status)
{
	char				*result;
	int					i;
	t_expansion_data	data;

	if (!str)
		return (NULL);
	result = ft_strdup("");
	if (!result)
		return (NULL);
	data.env = env;
	data.exit_status = exit_status;
	i = 0;
	while (str[i])
	{
		if (str[i] == '$' && (str[i + 1] == '?' || ft_is_var_char(str[i + 1]))
			&& ft_should_expand(str, i))
			result = ft_handle_variable_expansion(str, &i, result, &data);
		else
			result = ft_append_single_char(result, str[i++]);
		if (!result)
			return (NULL);
	}
	return (result);
}
