/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehossain <ehossain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/25 15:19:24 by ehossain          #+#    #+#             */
/*   Updated: 2025/10/25 15:20:58 by ehossain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

int	ft_is_argument_token(t_token_type type)
{
	return (type == TOKEN_WORD || type == TOKEN_SINGLE_QUOTE
		|| type == TOKEN_DOUBLE_QUOTE);
}

char	*ft_merge_adjacent_tokens(t_token **tokens)
{
	char	*result;
	char	*temp;
	char	*old_result;

	result = ft_strdup("");
	if (!result)
		return (NULL);
	while (*tokens && ft_is_argument_token((*tokens)->type))
	{
		temp = ft_strjoin(result, (*tokens)->value);
		if (!temp)
		{
			free(result);
			return (NULL);
		}
		old_result = result;
		result = temp;
		free(old_result);
		*tokens = (*tokens)->next;
	}
	return (result);
}
