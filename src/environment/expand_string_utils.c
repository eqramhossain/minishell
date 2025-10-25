/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_string_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekram <ekram@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/25 17:57:48 by ehossain          #+#    #+#             */
/*   Updated: 2025/10/25 18:18:29 by ekram            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "environment.h"
#include "tokenizer.h"

char	*ft_append_to_result(char *result, char *to_add)
{
	char	*new_result;

	if (!to_add)
		return (result);
	new_result = ft_strjoin(result, to_add);
	return (new_result);
}

int	ft_should_expand(char *str, int pos)
{
	int		i;
	char	quote;

	i = 0;
	quote = 0;
	while (i < pos && str[i])
	{
		if (!quote && ft_is_quote(str[i]))
			quote = str[i];
		else if (quote && str[i] == quote)
			quote = 0;
		i++;
	}
	if (quote == '\'')
		return (0);
	return (1);
}

char	*ft_extract_var_name(char *str, int *i)
{
	char	*var_name;
	int		len;
	int		j;

	len = ft_get_var_name_len(&str[*i]);
	var_name = ft_calloc(len + 1, sizeof(char));
	if (!var_name)
		return (NULL);
	j = 0;
	while (j < len)
	{
		var_name[j] = str[*i];
		(*i)++;
		j++;
	}
	var_name[j] = '\0';
	return (var_name);
}

char	*ft_get_variable_value(char *str, int *i, t_envp *env, int exit_status)
{
	char	*var_name;
	char	*value;

	if (str[*i] == '?')
	{
		(*i)++;
		return (ft_itoa(exit_status));
	}
	var_name = ft_extract_var_name(str, i);
	if (!var_name)
		return (ft_strdup(""));
	value = ft_get_env_value(var_name, env);
	free(var_name);
	if (!value)
		return (ft_strdup(""));
	return (ft_strdup(value));
}
