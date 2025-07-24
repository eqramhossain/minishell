/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehossain <ehossain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 14:42:57 by ehossain          #+#    #+#             */
/*   Updated: 2025/07/24 20:27:17 by ehossain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include "include.h"

void	ft_display_banner(void);
char	*ft_prompt(void);
char	*ft_strldup(const char *s, size_t len);
char	*ft_strjoin_free(char *str1, char *str2);

#endif
