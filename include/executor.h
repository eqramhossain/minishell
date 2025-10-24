/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehossain <ehossain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 22:03:21 by ehossain          #+#    #+#             */
/*   Updated: 2025/10/24 18:28:02 by ehossain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTOR_H
# define EXECUTOR_H

# include "builtins.h"
# include "environment.h"
# include "signals.h"
# include "structures_def.h"

int		ft_executor(t_ms_data *ms_data);

int		ft_execute_single_command(t_ms_data *ms_data, t_cmd *cmd);
int		ft_execute_external_single(t_ms_data *ms_data, t_cmd *cmd);
int		ft_execute_pipeline(t_ms_data *ms_data, t_cmd *cmd_list);

int		ft_is_builtin(char *cmd);
int		ft_execute_builtin(t_ms_data *ms_data, char **argv);

char	*ft_find_command_path(char *command, t_envp *env);
int		ft_apply_redirections(t_redir *redir_list);

#endif
