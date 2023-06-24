/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcoskun42 <hcoskun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/24 23:12:25 by hcoskun42         #+#    #+#             */
/*   Updated: 2023/06/24 23:12:26 by hcoskun42        ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_format(char format_char, va_list arg)
{
	char	*str;

	if (format_char == 'c')
		return (ft_putchar(va_arg(arg, int)));
	else if (format_char == 's')
		return (ft_putstr(va_arg(arg, char *)));
	else if (format_char == 'd' || format_char == 'i')
		return (ft_putstr(ft_itoa_base(va_arg(arg, int), 10)));
	else if (format_char == 'u')
		return (ft_putstr(ft_itoa_base((unsigned int) va_arg(arg, int), 10)));
	else if (format_char == 'x')
		return (ft_putstr(ft_itoa_base((unsigned int) va_arg(arg, int), 16)));
	else if (format_char == 'X')
	{
		str = ft_itoa_base((unsigned int) va_arg(arg, int), 16);
		return (ft_putstr(to_upper(str)));
	}
	else if (format_char == 'p')
	{
		str = ft_itoa_base(va_arg(arg, unsigned long), 16);
		return (ft_putstr("0x") + ft_putstr(str));
	}
	else
		return (ft_putchar(format_char));
}

int	ft_printf(const char *format, ...)
{
	int		i;
	int		sum_len;
	va_list	arguments;

	va_start (arguments, format);
	i = 0;
	sum_len = 0;
	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			sum_len += print_format(format[i], arguments);
		}
		else
			sum_len += ft_putchar(format[i]);
		i++;
	}
	va_end(arguments);
	return (sum_len);
}
