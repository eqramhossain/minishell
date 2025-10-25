/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expansion_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehossain <ehossain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 22:44:04 by ehossain          #+#    #+#             */
/*   Updated: 2025/10/24 22:44:07 by ehossain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "environment.h"

int	ft_is_var_char(char c)
{
	return (ft_isalnum(c) || c == '_');
}

int	ft_get_var_name_len(char *str)
{
	int	len;

	len = 0;
	if (str[0] == '?')
		return (1);
	while (str[len] && ft_is_var_char(str[len]))
		len++;
	return (len);
}

char	*ft_get_env_value(char *var_name, t_envp *env)
{
	t_envp	*current;

	if (!var_name || !env)
		return (NULL);
	current = env;
	while (current)
	{
		if (ft_strcmp(current->key, var_name) == 0)
			return (current->value);
		current = current->next;
	}
	return (NULL);
}
