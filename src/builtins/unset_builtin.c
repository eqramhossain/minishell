/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset_builtin.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehossain <ehossain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 11:30:58 by ehossain          #+#    #+#             */
/*   Updated: 2025/10/23 11:31:00 by ehossain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"

// unset - Remove environment variable
// TODO: Implement this properly!

int	ft_unset(char **args, t_ms_data *ms_data)
{
	(void)args;
	(void)ms_data;
	ft_putendl_fd("unset: not yet implemented", STDERR);
	return (0);
}
