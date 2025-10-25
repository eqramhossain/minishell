/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_builtin_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehossain <ehossain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/25 19:25:06 by ehossain          #+#    #+#             */
/*   Updated: 2025/10/25 19:26:22 by ehossain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"

int	is_valid_identifier(char *str)
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

void	print_export_error(char *arg)
{
	ft_putstr_fd("minishell: export: `", STDERR);
	ft_putstr_fd(arg, STDERR);
	ft_putendl_fd("': not a valid identifier", STDERR);
}

void	print_sorted_env(t_envp *env)
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

void	ft_envadd_back(t_envp **env, t_envp *new_node)
{
	t_envp	*current;

	if (!*env)
	{
		*env = new_node;
		return ;
	}
	current = *env;
	while (current->next)
		current = current->next;
	current->next = new_node;
}
