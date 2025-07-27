/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekram <ekram@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 19:07:35 by ehossain          #+#    #+#             */
/*   Updated: 2025/07/26 12:45:22 by ehossain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	ft_all_parsing_init(t_all_parsing *all_parsing);
// maybe i can start the execution part
int	main(int ac, char **av, char **envp)
{
	t_all_parsing	*all_parsing;
	char			*rl;

	(void)av;
	(void)envp;
	if (ac > 1)
		return (ft_strerror(RED "expected ---> [./minishell]" RESET), 1);
	all_parsing = ft_calloc(sizeof(t_all_parsing), 1);
	ft_all_parsing_init(all_parsing);
	ft_display_banner();
	while (1)
	{
		all_parsing->prompt = ft_prompt();
		rl = readline(all_parsing->prompt);
		if (!rl)
		{
			ft_putchar('\n');
			break ;
		}
		if (*rl)
			add_history(rl);
		all_parsing = ft_call_all_parsing(all_parsing, rl);
		free(rl);
	}
	free(all_parsing->prompt);
	free(all_parsing);
	return (0);
}

static void	ft_all_parsing_init(t_all_parsing *all_parsing)
{
	all_parsing->ast = NULL;
	all_parsing->lexer = NULL;
	all_parsing->parser = NULL;
	all_parsing->parser = NULL;
}
