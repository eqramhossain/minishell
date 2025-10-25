/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quote.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehossain <ehossain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 22:03:44 by ehossain          #+#    #+#             */
/*   Updated: 2025/10/24 22:06:01 by ehossain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char	*remove_quotes(const char *str)
{
	char	*result;
	int		i;
	char	quote;
	int		j;

	i = 0;
	j = 0;
	quote = 0;
	result = malloc(strlen(str) + 1);
	while (str[i])
	{
		if (!quote && (str[i] == '\'' || str[i] == '"'))
			quote = str[i]; // open quote
		else if (quote && str[i] == quote)
			quote = 0; // close quote
		else
			result[j++] = str[i]; // normal character
		i++;
	}
	result[j] = '\0';
	return (result);
}

int	main(int ac, char **av)
{
	char	*str;

	(void)ac;
	str = remove_quotes(av[1]);
	printf("str = %s\n", str);
}
