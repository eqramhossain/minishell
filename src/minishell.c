/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehossain <ehossain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/27 17:26:42 by ehossain          #+#    #+#             */
/*   Updated: 2025/08/05 15:30:29 by ehossain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "envp.h"
#include "minishell.h"
#include "signals.h"
#include "syntax.h"
#include "tokenize.h"
#include "utils.h"

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

void	ft_main_loop(t_ms_data *data)
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
		ft_ms_syntax_error(data->input);
		// data->token = ft_start_tokenizer(data->input);
		free(data->prompt);
	}
	free(data->prompt);
	ft_free_t_envp(&data->envp);
	free(data->envp);
}

// Check open and close Quote
// if (ft_check_close_quote(data->input) == 0)
// {
// 	ft_putstr_fd("Error: unclosed quote\n", STDOUT);
// 	continue ;
// }
