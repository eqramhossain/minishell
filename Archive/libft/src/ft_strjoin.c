/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehossain <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 12:11:56 by ehossain          #+#    #+#             */
/*   Updated: 2025/02/24 19:28:00 by ehossain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// int	main(void)
// {
// 	char	str1[] = "a;sldjkflasjdfl;jkasdf";
// 	char	str2[] = "hello";
// 	char	*ptr;
// 	char	*ptr2;
//
// 	ptr = ft_strjoin(str1, str2);
// 	ptr2 = strjoin(str1, str2);
// 	printf("%s\n", ptr);
// 	printf("%s\n", ptr);
// 	return (0);
// }

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	size_t	j;
	size_t	n;
	char	*dest;

	if (s1 == 0 || s2 == 0)
		return (NULL);
	n = ft_strlen(s1) + ft_strlen(s2) + 1;
	dest = malloc(sizeof(char) * n);
	if (!dest)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		dest[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j])
	{
		dest[j + i] = s2[j];
		j++;
	}
	dest[i + j] = '\0';
	return (dest);
}
