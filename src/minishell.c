/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekram <ekram@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 22:30:04 by ehossain          #+#    #+#             */
/*   Updated: 2025/10/25 19:42:47 by ekram            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void				ft_init_ms_data(t_ms_data *data, char **envp);

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
