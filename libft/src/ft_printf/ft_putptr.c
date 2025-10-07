/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehossain <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 16:18:15 by ehossain          #+#    #+#             */
/*   Updated: 2024/11/28 10:47:32 by ehossain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putptr(void *add)
{
	int				count;
	unsigned long	mem;

	count = 0;
	mem = (unsigned long)add;
	if (add == NULL)
		return (ft_putstr("(nil)"));
	count += ft_putstr("0x");
	count += ft_puthexa_ptr((unsigned long)mem);
	return (count);
}

int	ft_puthexa_ptr(unsigned long nb)
{
	int		count;
	char	*base;

	count = 0;
	base = "0123456789abcdef";
	if (nb > 15)
	{
		count += ft_puthexa_ptr(nb / 16);
		count += ft_puthexa_ptr(nb % 16);
	}
	else
	{
		count += ft_putchar(base[nb]);
	}
	return (count);
}
