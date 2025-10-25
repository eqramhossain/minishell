/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filter_empty.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehossain <ehossain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/25 15:23:51 by ehossain          #+#    #+#             */
/*   Updated: 2025/10/25 15:23:53 by ehossain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "environment.h"

static int	count_non_empty(char **arr)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	while (arr[i])
	{
		if (arr[i][0] != '\0')
			count++;
		i++;
	}
	return (count);
}

char	**ft_filter_empty_args(char **argv)
{
	char	**result;
	int		i;
	int		j;
	int		count;

	if (!argv)
		return (NULL);
	count = count_non_empty(argv);
	result = (char **)malloc(sizeof(char *) * (count + 1));
	if (!result)
		return (NULL);
	i = 0;
	j = 0;
	while (argv[i])
	{
		if (argv[i][0] != '\0')
		{
			result[j] = ft_strdup(argv[i]);
			if (!result[j])
			{
				ft_free_array(result);
				return (NULL);
			}
			j++;
		}
		i++;
	}
	result[j] = NULL;
	return (result);
}
