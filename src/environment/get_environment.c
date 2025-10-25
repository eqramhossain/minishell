/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_environment.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehossain <ehossain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 11:31:17 by ehossain          #+#    #+#             */
/*   Updated: 2025/10/25 17:48:55 by ehossain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "environment.h"

static void	ft_t_envp_init(t_envp **envp, int j);
static void	ft_lstadd_t_envp(t_envp **head, t_envp *new_lst);
static void	ft_getenv(t_envp **envp_node);

t_envp	*ft_get_envp(char **envp)
{
	size_t	i;
	size_t	j;
	t_envp	*node_envp;
	t_envp	*current_node;

	i = 0;
	while (envp[i])
	{
		j = 0;
		while (envp[i][j] != '=')
			j++;
		if (i == 0)
		{
			ft_t_envp_init(&node_envp, j);
			ft_strlcpy(node_envp->key, envp[i], j + 1);
		}
		else if (i > 0)
		{
			ft_t_envp_init(&current_node, j);
			ft_strlcpy(current_node->key, envp[i], j + 1);
			ft_lstadd_t_envp(&node_envp, current_node);
		}
		i++;
	}
	return (ft_getenv(&node_envp), node_envp);
}

static void	ft_t_envp_init(t_envp **envp, int j)
{
	*envp = ft_calloc(sizeof(t_envp), 1);
	(*envp)->key = ft_calloc(sizeof(char), j + 1);
	(*envp)->value = NULL;
	(*envp)->next = NULL;
}

static void	ft_lstadd_t_envp(t_envp **head, t_envp *new_lst)
{
	t_envp	*tmp;

	tmp = *head;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = new_lst;
}

static void	ft_getenv(t_envp **node_envp)
{
	t_envp	*current;
	char	*env_value;

	current = *node_envp;
	while (current != NULL)
	{
		env_value = getenv(current->key);
		if (env_value)
			current->value = ft_strdup(env_value);
		else
			current->value = NULL;
		current = current->next;
	}
}
