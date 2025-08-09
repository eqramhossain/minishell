/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roussada <roussada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 11:41:59 by roussada          #+#    #+#             */
/*   Updated: 2025/08/04 14:46:42 by ehossain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	ft_advance(t_lexer *lexer)
{
	return (lexer->input[lexer->pos++]);
}

int	ft_strcmp(const char *s1, const char *s2)
{
	size_t			i;
	unsigned char	*str1;
	unsigned char	*str2;

	i = 0;
	str1 = (unsigned char *)s1;
	str2 = (unsigned char *)s2;
	while ((s1[i] || s2[i]))
	{
		if (s1[i] != s2[i])
			return (str1[i] - str2[i]);
		i++;
	}
	return (0);
}

void	*ft_mmcpy(void *dest, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*dd;
	unsigned char	*ss;

	if (dest == NULL && src == NULL)
		return (NULL);
	dd = (unsigned char *)dest;
	ss = (unsigned char *)src;
	i = 0;
	while (i < n)
	{
		dd[i] = ss[i];
		i++;
	}
	return (dest);
}

void	*ft_realloc(void *ptr, size_t old_size, size_t new_size)
{
	void	*new_ptr;
	size_t	copy_size;

	if (ptr == NULL)
		return (malloc(new_size));
	if (new_size == 0)
	{
		free(ptr);
		return (NULL);
	}
	new_ptr = malloc(new_size);
	if (!new_ptr)
		return (NULL);
	if (old_size < new_size)
		copy_size = old_size;
	else
		copy_size = new_size;
	ft_memcpy(new_ptr, ptr, copy_size);
	free(ptr);
	return (new_ptr);
}

int	ft_isword(char c)
{
	if (c != '\0' && !ft_check_operator(c) && c != ' ' && c != '\t')
		// not space and operator and tab
		return (1);
	return (0);
}

char	ft_peak(t_lexer *lexer)
{
	if (lexer->input[lexer->pos])
		return (lexer->input[lexer->pos]);
	return ('\0');
}

/**
 * @brief This function skips the whitespaces
 *
 * @param lexer
 */
void	ft_skip_whitespace(t_lexer *lexer)
{
	while ((lexer->input[lexer->pos] != '\0') && (lexer->input[lexer->pos] == 32
			|| lexer->input[lexer->pos] == '\t'))
		lexer->pos++;
}

int	ft_check_operator(char c)
{
	if (c == '|')
		return (1);
	if (c == '<')
		return (1);
	if (c == '>')
		return (1);
	return (0);
}
