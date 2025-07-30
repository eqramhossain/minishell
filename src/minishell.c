/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehossain <ehossain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/27 17:26:42 by ehossain          #+#    #+#             */
/*   Updated: 2025/07/30 20:41:19 by ehossain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "envp.h"
#include "lexing.h"
#include "minishell.h"
#include "signals.h"
#include "utils.h"

int	main(int ac, char **av, char **envp)
{
	t_ms_data	data;
	t_lexing	lexing;

	(void)av;
	if (ac > 1)
		return (1);
	ft_inisialize_t_ms_data(&data, envp);
	ft_inisialize_t_lexing(&lexing);
	ft_main_loop(&data, &lexing);
	return (0);
}

void	ft_main_loop(t_ms_data *data, t_lexing *lexing)
{
	ft_display_banner();
	while (1)
	{
		data->prompt = ft_prompt(); // using malloc
		ft_sigquit();
		ft_sigint();
		data->input = readline(data->prompt);
		if (!data->input)
		{
			free(data->input);
			break ;
		}
		if (data->input)
			add_history(data->input);
		ft_putstr_fd(data->input, STDOUT);
		if (data->input[0])
			ft_putchar_fd('\n', STDOUT);
		free(data->prompt);
	}
	free(data->prompt);
	ft_free_t_envp(&data->envp);
	free(data->envp);
}
