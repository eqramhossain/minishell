/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekram <ekram@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/25 19:40:00 by ehossain          #+#    #+#             */
/*   Updated: 2025/10/25 19:45:26 by ehossain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	ft_process_input(t_ms_data *data);
static void	ft_handle_execution(t_ms_data *data);
static int	ft_read_input(t_ms_data *data);

void	ft_main_loop(t_ms_data *data)
{
	ft_setup_signal();
	while (1)
	{
		if (ft_read_input(data) == 0)
			break ;
		if (ft_process_input(data) == 0)
			continue ;
		ft_handle_execution(data);
	}
}

static int	ft_read_input(t_ms_data *data)
{
	data->prompt = ft_prompt();
	data->input = readline(data->prompt);
	free(data->prompt);
	data->prompt = NULL;
	if (g_signal == SIGINT)
	{
		data->exit_status = 130;
		g_signal = 0;
	}
	if (!data->input)
	{
		ft_free_ms_data(data);
		return (0);
	}
	return (1);
}

static int	ft_process_input(t_ms_data *data)
{
	if (data->input[0] == '\0' || ft_edge(data->input) != SUCCESS)
	{
		free(data->input);
		data->input = NULL;
		return (0);
	}
	add_history(data->input);
	if (ft_ms_syntax_error(data->input) != 0)
	{
		data->exit_status = 2;
		free(data->input);
		data->input = NULL;
		return (0);
	}
	return (1);
}

static void	ft_handle_execution(t_ms_data *data)
{
	data->tokens = ft_tokenize(data->input);
	if (data->tokens != NULL)
	{
		data->parser = ft_parser(data->tokens);
		if (data->parser != NULL)
		{
			ft_expand_variables(data);
			ft_process_quotes_full(data->parser->cmds);
			data->exit_status = ft_executor(data);
			ft_free_cmd(data->parser->cmds);
			data->parser->cmds = NULL;
			ft_free_parser(data->parser);
			data->parser = NULL;
		}
		ft_free_tokens(data->tokens);
		data->tokens = NULL;
	}
	else
		data->exit_status = 1;
	free(data->input);
	data->input = NULL;
}
