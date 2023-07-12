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
#include "libft/libft.h"

static char	digit2char(unsigned long long int digit)
{
	if (digit < 10)
		return ((char) digit + '0');
	else
		return ((char) digit - 10 + 'a');
}

static int	digits(unsigned long long int n, unsigned long long int base)
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

char	*ft_uitoa_base(unsigned long long nb, unsigned long long base)
{
	char	*result;
	int		digit_count;

	digit_count = digits(nb, base);
	result = (char *) malloc(sizeof(char) * (digit_count + 1));
	if (!result)
		return (NULL);
	result[digit_count] = '\0';
	while (digit_count)
	{
		result[digit_count - 1] = digit2char(nb % base);
		nb /= base;
		digit_count--;
	}
	return (result);
}
