#include "ft_printf.h"

char *toUpper(char *s) {
	int i;

	i = 0;
	while (s[i]) {
		if (s[i] >= 'a' && s[i] <= 'z')
			s[i] -= 32;
		i++;
	}
	return s;
}

int ft_putchar(char c) {
	write(1, &c, 1);
	return 1;
}

int ft_putstr(char *str) {
	int i;

	i = 0;
	while (str[i]) {
		ft_putchar(str[i]);
		i++;
	}
	return i;
}