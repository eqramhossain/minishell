/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntax.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekram <ekram@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 10:33:09 by gmarquis          #+#    #+#             */
/*   Updated: 2025/08/05 15:50:44 by ehossain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SYNTAX_H
# define SYNTAX_H

# include "all_include.h"

typedef struct s_syntax
{
	char	*input;
	size_t	len_input;
}			t_syntax;

int			ft_ms_syntax_error(char *input);

#endif
