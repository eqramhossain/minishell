/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_free.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehossain <ehossain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 20:12:21 by ehossain          #+#    #+#             */
/*   Updated: 2025/07/24 22:16:15 by ehossain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

char	*ft_strjoin_free(char *str1, char *str2)
{
	char	*tmp_buffer;

	tmp_buffer = ft_strjoin(str1, str2);
	if (!tmp_buffer)
	{
		free(str1);
		str1 = NULL;
		return (NULL);
	}
	free(str1);
	free(str2);
	return (tmp_buffer);
}
