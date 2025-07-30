/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehossain <ehossain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/27 17:27:23 by ehossain          #+#    #+#             */
/*   Updated: 2025/07/29 16:49:44 by ehossain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "envp.h"

typedef struct s_ms_data
{
	char	*read_line;
	char	*prompt;
	t_envp	*envp;
}			t_ms_data;

void		ft_main_loop(t_ms_data *data);

#endif
