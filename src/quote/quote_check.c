/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quote_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehossain <ehossain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/25 13:05:23 by ehossain          #+#    #+#             */
/*   Updated: 2025/10/25 14:14:03 by ehossain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "quote.h"

int	ft_check_quotes_closed(char *str)
{
	int		i;
	char	quote;

	if (!str)
		return (1);
	i = 0;
	quote = 0;
	while (str[i])
	{
		if (!quote && ft_is_quote(str[i]))
			quote = str[i];
		else if (quote && str[i] == quote)
			quote = 0;
		i++;
	}
	return (quote == 0);
}

int	ft_is_inside_quotes(char *str, int pos)
{
	return (ft_get_quote_state(str, pos) != 0);
}

char	ft_get_quote_type(char *str, int pos)
{
	if (!str || pos < 0)
		return (0);
	if (!ft_is_quote(str[pos]))
		return (0);
	if (pos == 0 || ft_get_quote_state(str, pos) == 0)
		return (str[pos]);
	return (0);
}
