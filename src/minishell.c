/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehossain <ehossain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/27 17:26:42 by ehossain          #+#    #+#             */
/*   Updated: 2025/07/29 19:48:26 by ehossain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "define.h"
#include "envp.h"
#include "minishell.h"
#include "signals.h"
#include "utils.h"

static void	ft_inisialize_t_ms_data(t_ms_data *data, char **envp);

int	main(int ac, char **av, char **envp)
{
	t_ms_data	data;

	(void)av;
	if (ac > 1)
		return (1);
	ft_inisialize_t_ms_data(&data, envp);
	ft_main_loop(&data);
	return (0);
}

static void	ft_inisialize_t_ms_data(t_ms_data *data, char **envp)
{
	data->read_line = NULL;
	data->prompt = NULL;
	data->envp = ft_get_envp(envp);
}

void	ft_main_loop(t_ms_data *data)
{
	ft_display_banner();
	while (1)
	{
		data->prompt = ft_prompt(); // using malloc
		ft_sigquit();
		ft_sigint();
		data->read_line = readline(data->prompt);
		if (!data->read_line)
		{
			free(data->read_line);
			break ;
		}
		if (data->read_line)
			add_history(data->read_line);
		ft_putstr_fd(data->read_line, STDOUT);
		if (data->read_line[0])
			ft_putchar_fd('\n', STDOUT);
		free(data->prompt);
	}
	free(data->prompt);
	ft_free_t_envp(&data->envp);
	free(data->envp);
}
