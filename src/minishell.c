/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehossain <ehossain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 22:30:04 by ehossain          #+#    #+#             */
/*   Updated: 2025/10/25 14:32:16 by ehossain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void				ft_init_ms_data(t_ms_data *data, char **envp);
static void				ft_main_loop(t_ms_data *data);
void					ft_free_ms_data(t_ms_data *data);

volatile sig_atomic_t	g_signal = 0;

int	main(int ac, char **av, char **envp)
{
	t_ms_data	data;

	(void)av;
	if (ac > 1)
		return (1);
	ft_init_ms_data(&data, envp);
	ft_main_loop(&data);
	return (data.exit_status);
}

static void	ft_init_ms_data(t_ms_data *data, char **envp)
{
	data->exit_status = 0;
	data->running = 1;
	data->prompt = NULL;
	data->input = NULL;
	data->envp_arg = envp;
	data->envp = ft_get_envp(envp);
	data->envp_cp = ft_get_envp(envp);
	data->tokens = NULL;
	data->parser = NULL;
}

static void	ft_main_loop(t_ms_data *data)
{
	if (isatty(STDIN))
		ft_display_banner();
	ft_setup_signal();
	while (1)
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
			// ft_putstr_fd("exit\n", STDERR);
			ft_free_ms_data(data);
			break ;
		}
		if (data->input[0] != '\0' && ft_edge(data->input) == SUCCESS)
		{
			add_history(data->input);
			if (ft_ms_syntax_error(data->input) != 0)
			{
				data->exit_status = 2;
				free(data->input);
				data->input = NULL;
				continue ;
			}
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
			{
				data->exit_status = 1;
			}
		}
		free(data->input);
		data->input = NULL;
	}
}

void	ft_free_ms_data(t_ms_data *data)
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
	rl_clear_history();
}
