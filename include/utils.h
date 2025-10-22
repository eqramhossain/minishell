/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehossain <ehossain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/08 12:29:29 by ehossain          #+#    #+#             */
/*   Updated: 2025/10/22 18:13:57 by ehossain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include "structures_def.h"

void	ft_display_banner(void);
char	*ft_prompt(void);
void	ft_free_prompt(char *str);

void	ft_free(void **content);
char	*ft_strjoin_free(char *str1, char *str2);
char	*ft_strldup(const char *s, size_t len);
int		ft_strcmp(const char *s1, const char *s2);
void	ft_putendl(char *str);
int		ft_edge(char *str);

#endif
