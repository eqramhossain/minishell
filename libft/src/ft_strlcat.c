/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehossain <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 14:04:20 by ehossain          #+#    #+#             */
/*   Updated: 2024/11/19 14:04:25 by ehossain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// int	main(void)
// {
// 	char	dst[15] = "hello ";
// 	char	src[5] = "world";
// 	size_t	i;
// 	size_t	j;
// 	size_t	i;
// 	size_t	dst_len;
// 	size_t	src_len;
//
// 	i = 5;
// 	j = ft_strlcat(dst, src, i);
// 	printf("j = %zd\n", j);
// 	printf("dst = %s\n", dst);
// 	return (0);
// }

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	dst_len;
	size_t	src_len;

	i = 0;
	dst_len = ft_strlen(dst);
	src_len = ft_strlen(src);
	if (size == 0 || size <= dst_len)
	{
		return (src_len + size);
	}
	while (src[i] != '\0' && (dst_len + i < (size - 1)))
	{
		dst[dst_len + i] = src[i];
		i++;
	}
	dst[dst_len + i] = '\0';
	return (dst_len + src_len);
}
