/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcuevas- <lcuevas-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 15:14:17 by lcuevas-          #+#    #+#             */
/*   Updated: 2023/10/02 14:25:50 by lcuevas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isascii(int c)
{
	if (c >= 0 && c <= 127)
		return (1);
	else
		return (0);
}

/* 
comprueba si está en la tabla ascii normal

#include <stdio.h>
#include <ctype.h>

int	main(void)
{
	char	c;

	c = 'f';
	printf ("%d\n", ft_isdigit(c));
	printf ("%d\n", isdigit(c));
	return (0);
}
*/