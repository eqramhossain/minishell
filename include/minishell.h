/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehossain <ehossain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 23:05:56 by ehossain          #+#    #+#             */
/*   Updated: 2025/10/25 14:18:35 by ehossain         ###   ########.fr       */
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

void							ft_free_ms_data(t_ms_data *data);

#endif
