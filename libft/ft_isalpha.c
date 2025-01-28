/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcuevas- <lcuevas-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 10:48:04 by lcuevas-          #+#    #+#             */
/*   Updated: 2023/10/02 14:11:23 by lcuevas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isalpha(int c)
{
	if ((c > 64 && c < 91) || (c > 96 && c < 123))
		return (1);
	else
		return (0);
}

/* 
comprueba si es alfabético

#include <stdio.h>

int	main(void)
{
	char	c;

	c = 'f';
	printf ("%d\n", ft_isalpha(c));
	printf ("%d\n", isalpha(c));
	return (0);
}
*/