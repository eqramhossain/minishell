/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quote.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehossain <ehossain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 22:03:44 by ehossain          #+#    #+#             */
/*   Updated: 2025/10/25 14:57:55 by ehossain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "quote.h"

char	*ft_remove_quotes(char *str)
{
	char	*result;
	int		i;
	int		j;
	char	in_quote;

	if (!str)
		return (NULL);
	result = (char *)malloc(sizeof(char) * (ft_strlen(str) + 1));
	if (!result)
		return (NULL);
	i = 0;
	j = 0;
	in_quote = 0;
	while (str[i])
	{
		if (!in_quote && (str[i] == '\'' || str[i] == '"'))
		{
			in_quote = str[i]; // Open a quote context
			i++;
			continue ; // Skip the opening quote character
		}
		else if (in_quote && str[i] == in_quote)
		{
			in_quote = 0; // Close the quote context
			i++;
			continue ; // Skip the closing quote character
		}
		// Copy everything else (including quotes that are inside other quotes)
		result[j++] = str[i];
		i++;
	}
	result[j] = '\0';
	return (result);
}
char	**ft_remove_quotes_array(char **arr)
{
	char	**result;
	int		i;
	int		count;

	if (!arr)
		return (NULL);
	count = 0;
	while (arr[count])
		count++;
	result = (char **)malloc(sizeof(char *) * (count + 1));
	if (!result)
		return (NULL);
	i = 0;
	while (i < count)
	{
		result[i] = ft_remove_quotes(arr[i]);
		if (!result[i])
		{
			ft_free_array(result);
			return (NULL);
		}
		i++;
	}
	result[i] = NULL;
	return (result);
}
