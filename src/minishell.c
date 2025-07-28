/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehossain <ehossain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/27 17:26:42 by ehossain          #+#    #+#             */
/*   Updated: 2025/07/28 15:02:45 by ehossain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "envp.h"
#include "free.h"
#include "minishell.h"
#include "utils.h"

static void	ft_inisialize_t_data(t_ms_data *data, char **envp);
void		ft_main_loop(t_ms_data *data);

int	main(int ac, char **av, char **envp)
{
	t_ms_data	data;

	(void)av;
	if (ac > 1)
		return (1);
	ft_inisialize_t_data(&data, envp);
	ft_main_loop(&data);
	ft_free_ms_data(&data);
	return (0);
}

static void	ft_inisialize_t_data(t_ms_data *data, char **envp)
{
	data->read_line = NULL;
	data->prompt = NULL;
	data->envp = ft_envp_init(envp);
}

void	ft_main_loop(t_ms_data *data)
{
	ft_display_banner();
	while (1)
	{
		data->prompt = ft_prompt();
		data->read_line = readline(data->prompt);
		if (!data->read_line)
			continue ;
		if (data->read_line)
			add_history(data->read_line);
		free(data->prompt);
	}
}
