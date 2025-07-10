/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehossain <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 12:32:40 by ehossain          #+#    #+#             */
/*   Updated: 2024/11/19 08:48:02 by ehossain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// int	main(void)
// {
// 	char	str[] = "hello w\0orld";
// 	char	*ptr;
// 	char	*ptr2;
//
// 	ptr = ft_strrchr(str, '\0');
// 	ptr2 = strrchr(str, '\0');
// 	printf("%s\n", ptr);
// 	printf("%s\n", ptr2);
// 	return (0);
// }

char	*ft_strrchr(const char *s, int c)
{
	size_t	i;
	char	*ptr_s;
	char	ptr_c;

	i = ft_strlen(s);
	ptr_s = (char *)s;
	ptr_c = (char)c;
	while (i > 0)
	{
		if (ptr_s[i] == ptr_c)
			return (&ptr_s[i]);
		i--;
	}
	if (ptr_s[i] == ptr_c)
		return (&ptr_s[i]);
	return (0);
}
