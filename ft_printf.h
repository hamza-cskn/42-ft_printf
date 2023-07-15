/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcoskun <hcoskun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/24 23:10:15 by hcoskun42         #+#    #+#             */
/*   Updated: 2023/07/15 16:34:37 by hcoskun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

int		ft_printf(const char *format, ...);

char	*to_upper(char *str);

int		ft_putchar(char c);

int		ft_putstr(char *str);

int		ft_putnbr(long long n);

int		ft_putunbr_base(unsigned long long n, unsigned long long base, int upper);

#endif
