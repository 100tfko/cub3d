/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcuevas- <lcuevas-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 11:55:45 by lcuevas-          #+#    #+#             */
/*   Updated: 2023/10/02 14:23:02 by lcuevas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	else
		return (0);
}

/* 
comprueba si es dígito

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
