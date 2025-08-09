/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ms_syntax_error.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehossain <ehossain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 15:24:41 by ehossain          #+#    #+#             */
/*   Updated: 2025/08/05 15:50:25 by ehossain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "syntax.h"

int	ft_ms_syntax_error(char *input)
{
	t_syntax	syntax;

	ft_memset(&syntax, 0, sizeof(t_syntax));
	syntax.input = ft_strtrim(input, " ");
	syntax.len_input = ft_strlen(syntax.input) - 1;
	return (0);
}
