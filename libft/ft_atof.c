/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcuevas- <lcuevas-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 14:57:04 by lcuevas-          #+#    #+#             */
/*   Updated: 2024/02/02 17:24:30 by lcuevas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

double	ft_floatify(const char *str)
{
	double	divisor;
	double	number;
	int		decimal_flag;

	divisor = 1.0;
	decimal_flag = 0;
	number = 0;
	while (*str >= '0' && *str <= '9')
	{
		number = (*str - '0') + (number * 10.0);
		str += 1;
	}
	if (*str == '.')
	{
		decimal_flag = 1;
		str += 1;
	}
	while (*str >= '0' && *str <= '9')
	{
		divisor /= 10.0;
		number += (*str - '0') * divisor;
		str += 1;
	}
	return (number);
}

double	ft_atof(const char *str)
{
	int		i;
	int		sign;
	double	number;

	i = 0;
	sign = 1;
	number = 0.0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i += 1;
	if ((str[i] == '+' || str[i] == '-')
		&& (str[i + 1] >= '0' && str[i + 1] <= '9'))
	{
		if (str[i] == '-')
			sign *= -1;
		i += 1;
	}
	number = ft_floatify(&str[i]);
	return (number * sign);
}
