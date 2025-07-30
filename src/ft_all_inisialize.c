/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_all_inisialize.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehossain <ehossain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 20:09:12 by ehossain          #+#    #+#             */
/*   Updated: 2025/07/30 20:16:03 by ehossain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexing.h"
#include "minishell.h"

void	ft_inisialize_t_ms_data(t_ms_data *data, char **envp)
{
	data->input = NULL;
	data->prompt = NULL;
	data->envp = ft_get_envp(envp);
}

void	ft_inisialize_t_lexing(t_lexing *lexing)
{
	lexing->input = NULL;
	lexing->curr_char = '\0';
	lexing->char_pos = 0;
	lexing->token_count = 0;
}
