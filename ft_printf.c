//	va_start ( arguments, num );va_arg(arguments, int)va_end ( arguments );


// printf("%d", va_arg(arguments, int));

#include "ft_printf.h"

int printFormat(char formatChar, va_list arguments) {
	if (formatChar == 'c') {
		return ft_putchar(va_arg(arguments, int));
	} else if (formatChar == 's') {
		return ft_putstr(va_arg(arguments, char *));
	} else if (formatChar == 'd') {
		return ft_putstr(ft_itoa_base(va_arg(arguments, int), 10));
	} else if (formatChar == 'i') {
		return ft_putstr(ft_itoa_base(va_arg(arguments, int), 10));
	} else if (formatChar == 'u') {
		return ft_putstr(ft_itoa_base((unsigned int) va_arg(arguments, int), 10));
	} else if (formatChar == 'x') {
		return ft_putstr(ft_itoa_base((unsigned int) va_arg(arguments, int), 16));
	} else if (formatChar == 'X') {
		return ft_putstr(toUpper(ft_itoa_base((unsigned int) va_arg(arguments, int), 16)));
	} else if (formatChar == 'p') {
		return ft_putstr("0x") + ft_putstr(ft_itoa_base(va_arg(arguments, unsigned long), 16));
	} else {
		return ft_putchar(formatChar);
	}
}


int ft_printf(const char *format, ...) {
	int i;
	int sum_len;
	va_list arguments;

	va_start (arguments, format);
	i = 0;
	sum_len = 0;
	while (format[i]) {
		if (format[i] == '%') {
			i++;
			sum_len += printFormat(format[i], arguments);
		} else {
			sum_len += ft_putchar(format[i]);
		}

		i++;
	}
	va_end(arguments);
	return sum_len;
}