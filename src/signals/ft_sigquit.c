/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sigquit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehossain <ehossain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 12:26:07 by ehossain          #+#    #+#             */
/*   Updated: 2025/10/22 14:42:48 by ehossain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "signals.h"

void	ft_sigquit(void)
{
	struct sigaction	sa;

	ft_memset(&sa, 0, sizeof(sa));
	sigemptyset(&sa.sa_mask);
	sa.sa_handler = SIG_IGN;
	sa.sa_flags = 0;
	if (sigaction(SIGQUIT, &sa, NULL) == -1)
	{
		perror("SIGQUIT");
		return ;
	}
}
