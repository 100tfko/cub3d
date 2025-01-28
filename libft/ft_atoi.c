/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcuevas- <lcuevas-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 12:08:00 by lcuevas-          #+#    #+#             */
/*   Updated: 2024/02/02 17:24:38 by lcuevas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(const char *str)
{
	int	i;
	int	sign;
	int	ret;

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

/*
podría usar más ufnciones propias como isdigit y eso

#include <stdio.h>

int	main(void)
{
	char	str[] = "   --+-1234qa33fwef ";
	int		ret;

	ret = ft_atoi(str);
	printf("%d", ret);
	return (0);
}*/
