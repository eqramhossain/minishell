/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthexa.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehossain <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 13:56:00 by ehossain          #+#    #+#             */
/*   Updated: 2024/11/28 10:33:42 by ehossain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_puthexa_min(unsigned int nb)
{
	int		count;
	char	*base;

	count = 0;
	base = "0123456789abcdef";
	if (nb > 15)
	{
		count += ft_puthexa_min(nb / 16);
		count += ft_puthexa_min(nb % 16);
	}
	else
	{
		count += ft_putchar(base[nb]);
	}
	return (count);
}

int	ft_puthexa_maj(unsigned int nb)
{
	int		count;
	char	*base;

	count = 0;
	base = "0123456789ABCDEF";
	if (nb > 15)
	{
		count += ft_puthexa_maj(nb / 16);
		count += ft_puthexa_maj(nb % 16);
	}
	else
	{
		count += ft_putchar(base[nb]);
	}
	return (count);
}
