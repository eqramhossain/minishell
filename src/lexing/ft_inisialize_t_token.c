/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_inisialize_t_token.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehossain <ehossain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 20:15:46 by ehossain          #+#    #+#             */
/*   Updated: 2025/07/30 20:15:57 by ehossain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexing.h"

void	ft_inisialize_t_token(t_token *token)
{
	token->type = 0;
	token->value = NULL;
	token->next = NULL;
}
