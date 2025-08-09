/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_token.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehossain <ehossain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 15:30:24 by ehossain          #+#    #+#             */
/*   Updated: 2025/08/04 17:28:02 by ehossain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tokenize.h"

void	ft_add_token(t_token **token, char *value, t_token_type type,
		size_t len)
{
	t_token	*head;
	t_token	*new_token;

	head = *token;
	while (head->next)
		head = head->next;
	new_token = ft_new_token(value, type, len);
	if (!new_token)
		return ;
	head->next = new_token;
}
