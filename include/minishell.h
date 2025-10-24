/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehossain <ehossain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 23:05:56 by ehossain          #+#    #+#             */
/*   Updated: 2025/10/24 18:27:45 by ehossain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "environment.h"
# include "executor.h"
# include "parser.h"
# include "signals.h"
# include "structures_def.h"
# include "syntax.h"
# include "tokenizer.h"
# include "utils.h"

void	ft_free_ms_data(t_ms_data *data);

#endif
