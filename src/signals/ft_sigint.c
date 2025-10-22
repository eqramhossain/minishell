/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sigint.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehossain <ehossain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 12:26:04 by ehossain          #+#    #+#             */
/*   Updated: 2025/10/22 14:42:56 by ehossain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "signals.h"

static void	ft_sigint_hadler(int signal, siginfo_t *info, void *contex);

void	ft_sigint(void)
{
	struct sigaction	sa;

	ft_memset(&sa, 0, sizeof(sa));
	// sa.sa_handler = SIG_IGN;
	sa.sa_sigaction = &ft_sigint_hadler;
	sa.sa_flags = SA_RESTART;
	sigemptyset(&sa.sa_mask);
	if (sigaction(SIGINT, &sa, NULL) == -1)
	{
		perror("SIGINT");
		return ;
	}
}

static void	ft_sigint_hadler(int signal, siginfo_t *info, void *contex)
{
	(void)info;
	(void)contex;
	(void)signal;
	write(STDOUT_FILENO, "\n", 1);
	rl_on_new_line();
	rl_redisplay();
}
