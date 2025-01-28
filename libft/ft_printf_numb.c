/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_numb.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcuevas- <lcuevas-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 13:01:02 by lcuevas-          #+#    #+#             */
/*   Updated: 2024/01/11 10:14:12 by lcuevas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_pointer(unsigned long long ptr, int *ret)
{
	ft_string("0x", ret);
	ft_hexa(ptr, 'x', ret);
}

void	ft_decimal(int n, int *ret)
{
	if (n == -2147483648)
		ft_string("-2147483648", ret);
	else
	{
		if (n < 0)
		{
			ft_printf_putchar('-', ret);
			n *= -1;
		}
		if (n >= 10)
			ft_decimal((n / 10), ret);
		ft_printf_putchar(((n % 10) + '0'), ret);
	}
}

void	ft_unsigned(unsigned int nb, int *ret)
{
	if (nb / 10 != 0)
		ft_unsigned(nb / 10, ret);
	ft_printf_putchar(nb % 10 + '0', ret);
}

void	ft_hexa(unsigned long long nb, char c, int *ret)
{
	if (nb / 16 != 0)
		ft_hexa(nb / 16, c, ret);
	if (c == 'x')
		ft_printf_putchar("0123456789abcdef"[nb % 16], ret);
	else if (c == 'X')
		ft_printf_putchar("0123456789ABCDEF"[nb % 16], ret);
}
