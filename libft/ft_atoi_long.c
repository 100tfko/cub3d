/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_long.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcuevas- <lcuevas-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 11:25:42 by lcuevas-          #+#    #+#             */
/*   Updated: 2024/02/07 12:26:18 by lcuevas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

long int	ft_atoi_long(const char *str)
{
	int			i;
	long int	sign;
	long int	ret;

	i = 0;
	sign = 1;
	ret = 0;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i += 1;
	if (str[i] == 45 || str[i] == 43)
	{
		if (str[i] == 45)
			sign *= -1;
		i += 1;
	}
	while (str[i] >= 48 && str[i] <= 57)
	{
		ret = (str[i] - 48) + (ret * 10);
		i += 1;
	}
	return (ret * sign);
}
