/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehossain <ehossain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 14:34:44 by ehossain          #+#    #+#             */
/*   Updated: 2025/10/23 11:36:42 by ehossain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SIGNALS_H
# define SIGNALS_H

# include "structures_def.h"

void	ft_setup_signal(void);
void	ft_setup_child_signals(void);
void	ft_sigquit(void);
void	ft_sigint(void);

#endif
