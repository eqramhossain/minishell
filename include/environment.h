/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   environment.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehossain <ehossain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/08 11:59:58 by ehossain          #+#    #+#             */
/*   Updated: 2025/10/24 22:27:28 by ehossain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENVIRONMENT_H
# define ENVIRONMENT_H

# include "structures_def.h"
# include "utils.h"

t_envp	*ft_get_envp(char **envp);
void	ft_free_t_envp(t_envp **envp_node);

char	**ft_envp_to_array(t_envp *env);
void	ft_free_array(char **array);

void	ft_expand_variables(t_ms_data *data);
char	*ft_expand_string(char *str, t_envp *env, int exit_status);
char	*ft_get_env_value(char *var_name, t_envp *env);
int		ft_is_var_char(char c);
int		ft_get_var_name_len(char *str);

#endif
