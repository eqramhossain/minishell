/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   environment.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehossain <ehossain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/08 11:59:58 by ehossain          #+#    #+#             */
/*   Updated: 2025/10/23 11:24:34 by ehossain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENVP_H
# define ENVP_H

# include "structures_def.h"

t_envp	*ft_get_envp(char **envp);
void	ft_free_t_envp(t_envp **envp_node);

char	**ft_envp_to_array(t_envp *env);
void	ft_free_array(char **array);

#endif
