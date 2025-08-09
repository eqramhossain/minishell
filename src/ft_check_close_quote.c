/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_close_quote.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehossain <ehossain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 18:57:36 by ehossain          #+#    #+#             */
/*   Updated: 2025/08/04 20:51:58 by ehossain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_check_close_quote(char *input)
{
	size_t	i;
	char	c;

	i = 0;
	c = 0;
	while (input[i] != '\0')
	{
		if (input[i] == SINGLE_QUOTE || input[i] == DOUBLE_QUOTE)
		{
			c = input[i];
			i++;
			while (input[i] && input[i] != c)
				i++;
			if (input[i] && input[i] == c)
				i++;
			else
				return (0);
		}
		else
			i++;
	}
	return (1);
}
