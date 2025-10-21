/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekram <ekram@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 23:06:31 by ehossain          #+#    #+#             */
/*   Updated: 2025/10/21 13:15:21 by ehossain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	ft_init_ms_data(t_ms_data *data, char **envp);
static void	ft_main_loop(t_ms_data *data);

int	main(int ac, char **av, char **envp)
{
	t_ms_data	data;

	(void)av;
	if (ac > 1)
		return (1);
	ft_init_ms_data(&data, envp);
	ft_main_loop(&data);
	return (0);
}

static void	ft_init_ms_data(t_ms_data *data, char **envp)
{
	data->prompt = NULL;
	data->input = NULL;
	data->envp_arg = envp;
	data->envp = ft_calloc(1, sizeof(t_envp));
	data->tokens = ft_calloc(1, sizeof(t_token));
}

static void	ft_main_loop(t_ms_data *data)
{
	ft_display_banner();
	// ft_setup_signals(); // Set up signal handlers for interactive mode
	while (1)
	{
		// Create prompt and get input
		data->prompt = ft_prompt();
		data->input = readline(data->prompt);
		free(data->prompt);
		data->prompt = NULL;
		// Handle EOF (Ctrl+D)
		if (!data->input)
		{
			ft_putstr_fd("\nexit\n", STDERR);
			break ;
		}
		// Skip empty inputs but add non-empty commands to history
		if (data->input[0] != '\0')
		{
			add_history(data->input);
			// Check for syntax errors before tokenization
			if (ft_ms_syntax_error(data->input) != 0)
			{
				data->exit_status = 258; // Bash uses 258 for syntax errors
				free(data->input);
				data->input = NULL;
				continue ;
			}
			data->tokens = ft_tokenize(data->input);
			if (data->tokens != NULL)
			{
				ft_print_tokens(data->tokens);
				// Tokenization successful - proceed with parsing
				// TODO: Parse tokens into command structures
				data->commands = ft_parse_commands(data->tokens);
				if (data->commands != NULL)
				{
					ft_print_commands(data->commands);
					//     // TODO: Expand environment variables
					//     // ft_expand_variables(data);
					//
					//     // TODO: Execute the commands
					//     // ft_execute_commands(data);
					//
					//     // TODO: Clean up command structures
					ft_free_commands(data->commands);
					data->commands = NULL;
				}
				// Clean up tokens after use
				ft_free_tokens(data->tokens);
				data->tokens = NULL;
			}
			else
			{
				// Tokenization failed
				data->exit_status = 1;
			}
		}
		// Always free input before next iteration
		free(data->input);
		data->input = NULL;
	}
	// // Final cleanup - free any remaining allocated memory
	// if (data->tokens)
	// 	ft_free_tokens(data->tokens);
	// if (data->envp)
	// 	ft_free_t_envp(&data->envp);
}
