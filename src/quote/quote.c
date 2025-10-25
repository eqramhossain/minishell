/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quote.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehossain <ehossain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 22:03:44 by ehossain          #+#    #+#             */
/*   Updated: 2025/10/25 17:24:08 by ehossain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "quote.h"

static int	ft_calculate_unquoted_len(char *str)
{
	int		len;
	int		i;
	char	in_quote;

	len = 0;
	i = 0;
	in_quote = 0;
	while (str[i])
	{
		if (!in_quote && (str[i] == '\'' || str[i] == '"'))
		{
			in_quote = str[i];
			i++;
			continue ;
		}
		else if (in_quote && str[i] == in_quote)
		{
			in_quote = 0;
			i++;
			continue ;
		}
		len++;
		i++;
	}
	return (len);
}

static void	ft_copy_without_quotes(char *str, char *result)
{
	int		i;
	int		j;
	char	in_quote;

	i = 0;
	j = 0;
	in_quote = 0;
	while (str[i])
	{
		if (!in_quote && (str[i] == '\'' || str[i] == '"'))
		{
			in_quote = str[i];
			i++;
			continue ;
		}
		else if (in_quote && str[i] == in_quote)
		{
			in_quote = 0;
			i++;
			continue ;
		}
		result[j++] = str[i];
		i++;
	}
	result[j] = '\0';
}

char	*ft_remove_quotes(char *str)
{
	char	*result;
	int		len;

	if (!str)
		return (NULL);
	len = ft_calculate_unquoted_len(str);
	result = (char *)malloc(sizeof(char) * (len + 1));
	if (!result)
		return (NULL);
	ft_copy_without_quotes(str, result);
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
			return (ft_free_array(result), NULL);
		i++;
	}
	result[i] = NULL;
	return (result);
}
