/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehossain <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 09:41:52 by ehossain          #+#    #+#             */
/*   Updated: 2025/06/28 20:16:45 by ehossain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief this function find the little string in the big string
 *
 * @param big
 * @param little
 * @param len
 * @return
 */
char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;
	char	*ptr_big;
	char	*ptr_little;

	i = 0;
	ptr_big = (char *)big;
	ptr_little = (char *)little;
	if (ptr_little[0] == '\0' || ptr_little == NULL)
		return (ptr_big);
	while (ptr_big[i] != '\0' && i < len)
	{
		j = 0;
		while ((ptr_little[j] == ptr_big[i + j]) && ((i + j) < len)
			&& (ptr_big[i + j]))
		{
			j++;
		}
		if (ptr_little[j] == '\0')
			return (ptr_big + i);
		i++;
	}
	return (NULL);
}
