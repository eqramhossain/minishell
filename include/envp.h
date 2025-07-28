/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   envp.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehossain <ehossain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 14:30:57 by ehossain          #+#    #+#             */
/*   Updated: 2025/07/28 14:35:31 by ehossain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENVP_H
# define ENVP_H

# include "all_include.h"

typedef struct s_envp
{
	char			*key;
	char			*value;
	struct s_envp	*next;
}					t_envp;

t_envp				*ft_envp_init(char **envp);

#endif
