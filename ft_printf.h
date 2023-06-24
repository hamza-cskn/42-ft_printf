#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

int ft_printf(const char *, ...);

char *toUpper(char *s);

int ft_putchar(char c);

int ft_putstr(char *str);

char *ft_itoa_base(long nb, int base);

# endif