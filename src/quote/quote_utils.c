/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quote_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekram <ekram@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/25 13:05:10 by ehossain          #+#    #+#             */
/*   Updated: 2025/10/25 14:25:32 by ekram            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "quote.h"

char	ft_get_quote_state(char *str, int pos)
{
	int		i;
	char	quote;

	i = 0;
	quote = 0;
	while (i < pos && str[i])
	{
		if (!quote && ft_is_quote(str[i]))
			quote = str[i];
		else if (quote && str[i] == quote)
			quote = 0;
		i++;
	}
	return (quote);
}

int	ft_find_closing_quote(char *str, int start)
{
	char	quote;
	int		i;

	if (!str || !ft_is_quote(str[start]))
		return (-1);
	quote = str[start];
	i = start + 1;
	while (str[i])
	{
		if (str[i] == quote)
			return (i);
		i++;
	}
	return (-1);
}

size_t	ft_count_unquoted_len(char *str)
{
	size_t	len;
	int		i;
	char	quote;

	if (!str)
		return (0);
	len = 0;
	i = 0;
	quote = 0;
	while (str[i])
	{
		if (!quote && ft_is_quote(str[i]))
			quote = str[i];
		else if (quote && str[i] == quote)
			quote = 0;
		else
			len++;
		i++;
	}
	return (len);
}
