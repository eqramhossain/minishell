/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehossain <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 11:49:47 by ehossain          #+#    #+#             */
/*   Updated: 2024/11/18 16:41:58 by ehossain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//
// int	main(void)
// {
// 	char	str[] = "hello w\0orld";
// 	char	*ptr;
// 	char	*ptr2;
//
// 	ptr = ft_strchr(str, '\0');
// 	ptr2 = strchr(str, '\0');
// 	printf("%s\n", ptr);
// 	printf("%s\n", ptr2);
// 	return (0);
// }

char	*ft_strchr(const char *s, int c)
{
	size_t	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == (char)c)
			return ((char *)&s[i]);
		i++;
	}
	if (s[i] == (char)c)
		return ((char *)&s[i]);
	return (0);
}
