/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   itoa.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcoskun42 <hcoskun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/24 23:23:05 by hcoskun42         #+#    #+#             */
/*   Updated: 2023/06/24 23:23:06 by hcoskun42        ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	digit2char(long digit)
{
	if (digit < 10)
		return ((char) digit + '0');
	else
		return ((char) digit - 10 + 'a');
}

static int	digits(long n, int base)
{
	int	i;

	if (n == 0)
		return (1);
	i = 0;
	while (n != 0)
	{
		n /= base;
		i++;
	}
	return (i);
}

static void	natural_itoa_base(long nb, int base, char *str)
{
	if (nb >= base)
		natural_itoa_base(nb / base, base, str - 1);
	*str = digit2char(nb % base);
}

char	*ft_itoa_base(long nb, int base)
{
	char	*result;
	int		len;
	int		is_negative;
	int		digit_count;

	is_negative = nb < 0;
	if (is_negative)
		nb = -nb;
	digit_count = digits(nb, base);
	len = digit_count + is_negative;
	result = (char *) malloc(sizeof(char) * (len + 1));
	if (!result)
		return (NULL);
	if (is_negative)
		*result = '-';
	natural_itoa_base(nb, base, result + len - 1);
	result[len] = '\0';
	return (result);
}
