/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehossain <ehossain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 14:40:39 by ehossain          #+#    #+#             */
/*   Updated: 2025/08/04 17:47:30 by ehossain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tokenize.h"

/**
 * @brief
 *
 * this fucntion will skip all the space and tab character
 *
 * @param var
 */
void	ft_skip_whitespaces(t_var_token *var)
{
	if (var->input[var->curr_pos] != '\0')
	{
		while (var->input[var->curr_pos] == SPACE
			&& var->input[var->curr_pos] == TAB)
		{
			var->curr_pos++;
		}
	}
}

/**
 * @brief
 *
 * this function is a safe check for curr_char until it arrives at '\0'
 *
 * @param var
 * @return
 */
char	ft_get_curr_char(t_var_token *var)
{
	if (var->input[var->curr_pos] != '\0')
		return (var->input[var->curr_pos]);
	return ('\0');
}

/**
 * @brief
 * this function check if the curr_char is an pipe or a redirection
 *
 * in case of success it return true = 1 otherwise return false = 0
 *
 * @param var
 * @return
 */
int	ft_check_operator(t_var_token *var)
{
	if (var->curr_char == PIPE)
		return (1);
	if (var->curr_char == REDIR_IN)
		return (1);
	if (var->curr_char == REDIR_OUT)
		return (1);
	return (0);
}
