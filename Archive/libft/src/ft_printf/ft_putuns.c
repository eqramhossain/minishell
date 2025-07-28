/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putuns.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehossain <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 11:48:31 by ehossain          #+#    #+#             */
/*   Updated: 2025/02/28 14:08:41 by ehossain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putuns(unsigned int nb)
{
	int	count;

	count = ft_number_size_printf((long int)nb);
	if (nb == 4294967295)
	{
		return (write(1, "4294967295", 10));
	}
	if (nb > 9)
	{
		ft_putuns(nb / 10);
		ft_putchar(nb % 10 + '0');
	}
	else
	{
		ft_putchar(nb % 10 + '0');
	}
	return (count);
}
