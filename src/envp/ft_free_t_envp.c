/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_t_envp.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehossain <ehossain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 18:01:11 by ehossain          #+#    #+#             */
/*   Updated: 2025/07/29 19:29:46 by ehossain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "envp.h"

void	ft_free_t_envp(t_envp **envp_node)
{
	t_envp	*current;
	t_envp	*next;

	current = *envp_node;
	while (current != NULL) // Continue until NULL
	{
		next = current->next; // Save next before freeing current
		if (current->key)
			free(current->key);
		if (current->value)
			free(current->value);
		free(current);
		current = next; // Move to next node
	}
	*envp_node = NULL; // Set pointer to NULL to prevent double-free
}
