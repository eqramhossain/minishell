/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehossain <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 08:20:47 by ehossain          #+#    #+#             */
/*   Updated: 2024/11/23 10:08:57 by ehossain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*ptr_s;

	i = 0;
	if (!s)
		return (NULL);
	if (start >= ft_strlen(s))
		return (ft_strdup(""));
	if (len > ft_strlen(s) - start)
		len = ft_strlen(s) - start;
	ptr_s = (char *)malloc(len + 1);
	if (!ptr_s)
		return (NULL);
	while (s[start] && i < len)
	{
		ptr_s[i] = s[start];
		i++;
		start++;
	}
	ptr_s[i] = '\0';
	return (ptr_s);
}
