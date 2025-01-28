/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcuevas- <lcuevas-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 17:07:37 by lcuevas-          #+#    #+#             */
/*   Updated: 2023/10/02 15:58:31 by lcuevas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static int	ft_potency(long int n)
{
	int	i;

	i = 1;
	while (n / 10 != 0)
	{
		i += 1;
		n /= 10;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	char	*str;
	int		pot;
	int		sign;

	sign = 1;
	if (n < 0)
		sign = -1;
	pot = ft_potency(n);
	if (n < 0)
		pot += 1;
	str = (char *)malloc((pot * sizeof(char) + 1));
	if (!str)
		return (0);
	str[pot] = 0;
	pot -= 1;
	while (pot >= 0)
	{
		str[pot] = ((n % 10) * sign) + '0';
		pot -= 1;
		n /= 10;
	}
	if (sign < 0)
		str[0] = '-';
	return (str);
}
/*
#include <stdio.h>

int	main(void)
{
	int		n;
	char	*str;

	n = -1234;
	str = ft_itoa(n);
	printf("%s\n", str);
	return (0);
}
*/