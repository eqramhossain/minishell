/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_new_token.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehossain <ehossain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 15:37:18 by ehossain          #+#    #+#             */
/*   Updated: 2025/08/04 16:02:33 by ehossain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tokenize.h"

t_token	*ft_new_token(char *value, t_token_type type, size_t len)
{
	t_token	*new_lst;

	new_lst = ft_calloc(sizeof(t_token), 1);
	if (!new_lst)
		return (NULL);
	new_lst->value = ft_strldup(value, len);
	new_lst->type = type;
	new_lst->next = NULL;
	return (new_lst);
}
