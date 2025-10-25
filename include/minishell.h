/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekram <ekram@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 23:05:56 by ehossain          #+#    #+#             */
/*   Updated: 2025/10/25 19:44:54 by ehossain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "environment.h"
# include "executor.h"
# include "parser.h"
# include "quote.h"
# include "signals.h"
# include "structures_def.h"
# include "syntax.h"
# include "tokenizer.h"
# include "utils.h"

extern volatile sig_atomic_t	g_signal;

void							ft_main_loop(t_ms_data *data);
void							ft_free_ms_data(t_ms_data *data);

void							ft_free_data_structures(t_ms_data *data);
void							ft_free_environment(t_ms_data *data);
void							ft_free_input_prompt(t_ms_data *data);

#endif
