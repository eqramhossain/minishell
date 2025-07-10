/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehossain <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 09:35:37 by ehossain          #+#    #+#             */
/*   Updated: 2025/06/24 17:24:27 by ehossain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

int				ft_printf(const char *format, ...);
int				ft_putchar(char c);
int				ft_putstr(const char *str);
int				ft_find_format(char format, va_list args);
int				ft_putdec(int nb);
int				ft_putuns(unsigned int nb);
unsigned int	ft_number_size_printf(long int nb);
int				ft_puthexa_min(unsigned int nb);
int				ft_puthexa_maj(unsigned int nb);
int				ft_putptr(void *add);

#endif
