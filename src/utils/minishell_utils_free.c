/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_utils_free.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehossain <ehossain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/25 19:45:44 by ehossain          #+#    #+#             */
/*   Updated: 2025/10/25 19:45:56 by ehossain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_free_data_structures(t_ms_data *data)
{
	if (data->tokens)
	{
		ft_free_tokens(data->tokens);
		data->tokens = NULL;
	}
	if (data->parser)
	{
		ft_free_parser(data->parser);
		data->parser = NULL;
	}
}

void	ft_free_environment(t_ms_data *data)
{
	if (data->envp)
	{
		ft_free_t_envp(&data->envp);
		data->envp = NULL;
	}
	if (data->envp_cp)
	{
		ft_free_t_envp(&data->envp_cp);
		data->envp_cp = NULL;
	}
}

void	ft_free_input_prompt(t_ms_data *data)
{
	if (data->input)
	{
		free(data->input);
		data->input = NULL;
	}
	if (data->prompt)
	{
		free(data->prompt);
		data->prompt = NULL;
	}
}

void	ft_free_ms_data(t_ms_data *data)
{
	ft_free_data_structures(data);
	ft_free_environment(data);
	ft_free_input_prompt(data);
	rl_clear_history();
}
