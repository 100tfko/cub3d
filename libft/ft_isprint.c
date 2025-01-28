/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcuevas- <lcuevas-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 15:21:58 by lcuevas-          #+#    #+#             */
/*   Updated: 2023/10/02 14:27:18 by lcuevas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isprint(int c)
{
	if (c >= 32 && c <= 126)
		return (1);
	return (0);
}

/* 
comprueba si es printable

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