/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_char.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcuevas- <lcuevas-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 13:00:45 by lcuevas-          #+#    #+#             */
/*   Updated: 2024/01/11 10:14:00 by lcuevas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_printf_putchar(char c, int *ret)
{
	if (*ret == -1)
		return ;
	if (write (1, &c, 1) == -1)
		(*ret = -2);
	*ret += 1;
}

void	ft_string(char *str, int *ret)
{
	int	i;

	i = 0;
	if (!str)
		return (ft_string("(null)", ret));
	while (str[i])
	{
		ft_printf_putchar((str[i]), ret);
		i += 1;
	}
}
