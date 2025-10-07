/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehossain <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 11:44:03 by ehossain          #+#    #+#             */
/*   Updated: 2025/02/25 19:26:30 by ehossain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*ft_calloc_gnl(size_t nmemb, size_t size)
{
	unsigned char	*ptr;
	size_t			i;

	i = 0;
	ptr = malloc(nmemb * size);
	if (!ptr)
		return (NULL);
	while (i < nmemb)
	{
		ptr[i] = 0;
		i++;
	}
	return (ptr);
}

size_t	ft_strlen_gnl(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

char	*ft_strchr_gnl(const char *str, int i)
{
	size_t	count;

	count = 0;
	while (str[count] != '\0')
	{
		if (str[count] == (char)i)
			return ((char *)&str[count]);
		count++;
	}
	if (str[count] == (char)i)
		return ((char *)&str[count]);
	return (NULL);
}

char	*ft_strjoin_gnl(char const *s1, char const *s2)
{
	size_t	i;
	size_t	j;
	size_t	n;
	char	*dest;

	if (!s1 || !s2)
		return (NULL);
	i = 0;
	j = 0;
	n = ft_strlen_gnl(s1) + ft_strlen_gnl(s2) + 1;
	dest = ft_calloc_gnl(n, sizeof(char));
	if (!dest)
		return (NULL);
	while (s1[i])
	{
		dest[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		dest[j + i] = s2[j];
		j++;
	}
	dest[i + j] = '\0';
	return (dest);
}

char	*ft_str_free_join_gnl(char *str1, char *str2)
{
	char	*tmp_buffer;

	tmp_buffer = ft_strjoin_gnl(str1, str2);
	if (!tmp_buffer)
	{
		free(str1);
		str1 = NULL;
		return (NULL);
	}
	free(str1);
	str1 = NULL;
	return (tmp_buffer);
}
