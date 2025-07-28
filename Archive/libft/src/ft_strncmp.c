/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehossain <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 19:06:09 by ehossain          #+#    #+#             */
/*   Updated: 2024/11/19 09:01:14 by ehossain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	unsigned char	*ptr_s1;
	unsigned char	*ptr_s2;

	i = 0;
	ptr_s1 = (unsigned char *)s1;
	ptr_s2 = (unsigned char *)s2;
	while (ptr_s1[i] == ptr_s2[i] && (ptr_s1[i]) && (ptr_s2[i]) && (i < n))
	{
		i++;
	}
	if (n == i)
	{
		return (0);
	}
	return (ptr_s1[i] - ptr_s2[i]);
}
