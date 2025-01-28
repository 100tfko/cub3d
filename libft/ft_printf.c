/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcuevas- <lcuevas-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 10:29:40 by lcuevas-          #+#    #+#             */
/*   Updated: 2024/01/11 10:14:40 by lcuevas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_conver(char const *content, int i, va_list *arg, int *ret)
{
	int	count;

	count = 0;
	if (content[i] == 'c')
		ft_printf_putchar(va_arg(*arg, int), ret);
	else if (content[i] == 's')
		ft_string(va_arg(*arg, char *), ret);
	else if (content[i] == 'p')
		ft_pointer(va_arg(*arg, unsigned long long), ret);
	else if (content[i] == 'd' || content[i] == 'i')
		ft_decimal(va_arg(*arg, int), ret);
	else if (content[i] == 'u')
		ft_unsigned(va_arg(*arg, unsigned int), ret);
	else if (content[i] == 'x')
		ft_hexa(va_arg(*arg, unsigned int), 'x', ret);
	else if (content[i] == 'X')
		ft_hexa(va_arg(*arg, unsigned int), 'X', ret);
	else if (content[i] == '%')
		ft_printf_putchar('%', ret);
}

int	ft_printf(char const *content, ...)
{
	int		i;
	int		ret;
	va_list	arg;

	i = 0;
	ret = 0;
	va_start(arg, content);
	while (content[i])
	{
		if (ret == -1)
			return (-1);
		if (content[i] != '%')
			ft_printf_putchar(content[i], &ret);
		else
		{
			i += 1;
			ft_conver(content, i, &arg, &ret);
		}
		i += 1;
	}
	va_end(arg);
	return (ret);
}
