/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehossain <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 09:40:41 by ehossain          #+#    #+#             */
/*   Updated: 2024/12/03 13:58:30 by ehossain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *format, ...);

// int	main(void)
// {
// 	int		total;
// 	char	c;
// 	char	str[] = "This is a string";
//
// 	total = 0;
// 	c = 'c';
// 	total += printf("This is a char = %c\n", c);
// 	total += printf("This is a string = %s\n", str);
// 	total += printf("This is a decimal = %d et %d\n", 2147483647, -2147483648);
// 	total += printf("This is a int = %i et %i\n", 2147483647, -2147483648);
// 	total += printf("This is a unsigned = %u et %u\n", 4294967295, 0);
// 	total += printf("This is a %% sign\n");
// 	total += printf("This is hexa num %X et %X\n", 2147483647, -2147483648);
// 	total += printf("This is hexa num %x et %x\n", 2147483647, -2147483648);
// 	total += printf("This is a memory address %p\n", &total);
// 	total += printf("This is a mrmory address %p\n", 0);
// 	total += printf("This is a wired test %d\n", printf(0));
// 	printf("The total Printed = %d\n", total);
// 	total = 0;
// 	total += ft_printf("This is a char = %c\n", c);
// 	total += ft_printf("This is a string = %s\n", str);
// 	total += ft_printf("This is a decimal = %d et %d\n", 2147483647,
// 			-2147483648);
// 	total += ft_printf("This is a int = %i et %i\n", 2147483647, -2147483648);
// 	total += ft_printf("This is a unsigned = %u et %u\n", 4294967295, 0);
// 	total += ft_printf("This is a %% sign\n");
// 	total += ft_printf("This is hexa num %X et %X\n", 2147483647, -2147483648);
// 	total += ft_printf("This is hexa num %x et %x\n", 2147483647, -2147483648);
// 	total += ft_printf("This is a memory address %p\n", &total);
// 	total += ft_printf("This is a memory address %p\n", 0);
// 	total += ft_printf("This is a wired test %d\n", ft_printf(0));
// 	ft_printf("The total Printed = %d\n", total);
// 	return (0);
// }

int	ft_printf(const char *format, ...)
{
	int		i;
	int		len;
	va_list	args;

	i = 0;
	len = 0;
	if (format == NULL)
		return (-1);
	va_start(args, format);
	while (format[i] != '\0')
	{
		if (format[i] == '%')
		{
			i++;
			len = len + ft_find_format(format[i], args);
		}
		else
			len = len + ft_putchar(format[i]);
		i++;
	}
	va_end(args);
	return (len);
}
