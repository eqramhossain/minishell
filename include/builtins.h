/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehossain <ehossain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 17:04:22 by ehossain          #+#    #+#             */
/*   Updated: 2025/10/22 17:39:19 by ehossain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTINS_H
# define BUILTINS_H

# include "structures_def.h"
# include "utils.h"

int	ft_pwd(void);
int	ft_echo(char **args);
int	ft_envp(t_envp *env);

#endif
