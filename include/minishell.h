/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehossain <ehossain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/27 17:27:23 by ehossain          #+#    #+#             */
/*   Updated: 2025/07/30 20:26:54 by ehossain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# define STDIN 0
# define STDOUT 1
# define STDERR 2

# include "envp.h"
# include "lexing.h"
# include "parsing.h"

typedef struct s_ms_data
{
	char		*input;
	char		*prompt;
	t_envp		*envp;
	t_lexing	*lexing;
	t_parsing	*parsing;
}				t_ms_data;

void			ft_main_loop(t_ms_data *data, t_lexing *lexing);

void			ft_inisialize_t_ms_data(t_ms_data *data, char **envp);
void			ft_inisialize_t_lexing(t_lexing *lexing);

#endif
