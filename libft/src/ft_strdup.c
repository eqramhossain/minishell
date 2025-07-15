/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehossain <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 14:28:19 by ehossain          #+#    #+#             */
/*   Updated: 2025/07/15 13:20:40 by ehossain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// int	main(void)
// {
// 	char	str[] = "hello ";
// 	char	*ptr;
//
// 	ptr = ft_strdup(str);
// 	printf("%s\n", ptr);
// 	return (0);
// }

char	*ft_strdup(const char *s)
{
	size_t	i;
	size_t	strlen_s;
	char	*ptr;

	i = 0;
	strlen_s = ft_strlen(s);
	ptr = malloc(sizeof(char) * strlen_s + 1);
	if (!ptr)
		return (NULL);
	while (s[i] != '\0' && i < strlen_s)
	{
		ptr[i] = s[i];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}
