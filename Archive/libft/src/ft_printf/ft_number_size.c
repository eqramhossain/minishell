/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_number_size.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehossain <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 13:34:08 by ehossain          #+#    #+#             */
/*   Updated: 2025/02/28 14:06:15 by ehossain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

unsigned int	ft_number_size_printf(long int nb)
{
	int	i;

	i = 0;
	if (nb == 0)
		return (1);
	if (nb < 0)
		i++;
	while (nb != 0)
	{
		nb = nb / 10;
		i++;
	}
	return (i);
}
