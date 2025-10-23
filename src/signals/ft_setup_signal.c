/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_setup_signal.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehossain <ehossain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 14:43:12 by ehossain          #+#    #+#             */
/*   Updated: 2025/10/23 11:36:07 by ehossain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "signals.h"

volatile sig_atomic_t	g_signal = 0;

void	ft_setup_signal(void)
{
	ft_sigint();
	ft_sigquit();
}

/**
 * Setup default signal handlers for child processes
 * Children should handle signals normally (not like the shell)
 */
void	ft_setup_child_signals(void)
{
	signal(SIGINT, SIG_DFL);
	signal(SIGQUIT, SIG_DFL);
}
