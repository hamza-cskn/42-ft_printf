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
#include "libft/libft.h"

char *safe_add_prefix(char *prefix, char *str)
{
	char	*new_str;

	new_str = ft_strjoin(prefix, str);
	free(str);
	return (new_str);
}

int	print_format(char format_char, va_list arg)
{
	char	*str;
	int		len;

	if (format_char == 'c')
		return (ft_putchar(va_arg(arg, int)));
	else if (format_char == 's')
		return (ft_putstr(va_arg(arg, char *)));
	else if (format_char == 'd' || format_char == 'i')
		str = ft_itoa(va_arg(arg, int));
	else if (format_char == 'u')
		str = ft_uitoa_base(va_arg(arg, unsigned int), 10);
	else if (format_char == 'x')
		str = (ft_uitoa_base(va_arg(arg, unsigned int), 16));
	else if (format_char == 'X')
		str = to_upper(ft_uitoa_base(va_arg(arg, unsigned int), 16));
	else if (format_char == 'p')
		str = safe_add_prefix("0x", ft_uitoa_base(va_arg(arg, unsigned long long), 16));
	else
		return (ft_putchar(format_char));
	len = ft_putstr(str);
	free(str);
	return (len);
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
