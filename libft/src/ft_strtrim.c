/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehossain <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 10:33:45 by ehossain          #+#    #+#             */
/*   Updated: 2025/08/05 15:37:13 by ehossain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// int	main(void)
// {
// 	char	set[] = "PATH=";
// 	char	str[] = "PATH=/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin:/home/ekram/.local/bin:/home/ekram/.local/bin";
// 	char	*ptr;
//
// 	ptr = ft_strtrim(str, set);
// 	printf("%s\n", ptr);
// 	return (0);
// }

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	i;
	size_t	j;
	char	*ptr_s;

	ptr_s = 0;
	if (s1 != 0 && set != 0)
	{
		i = 0;
		j = ft_strlen(s1);
		while (s1[i] && ft_strchr(set, s1[i]))
			i++;
		while (s1[j - 1] && ft_strchr(set, s1[j - 1]) && j > i)
			j--;
		ptr_s = (char *)malloc(sizeof(char) * (j - i + 1));
		if (ptr_s)
			ft_strlcpy(ptr_s, &s1[i], j - i + 1);
	}
	return (ptr_s);
}
