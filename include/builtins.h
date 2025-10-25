/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehossain <ehossain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 17:04:22 by ehossain          #+#    #+#             */
/*   Updated: 2025/10/25 12:55:02 by ehossain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTINS_H
# define BUILTINS_H

# include "environment.h"
# include "structures_def.h"
# include "utils.h"

int	ft_pwd(void);
int	ft_echo(char **args);
int	ft_envp(t_envp *env);
int	ft_cd(char **args, t_ms_data *ms_data);
int	ft_export(char **args, t_ms_data *ms_data);
int	ft_unset(char **args, t_ms_data *ms_data);
int	ft_exit(char **args, t_ms_data *ms_data);

#endif
