/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcuevas- <lcuevas-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 14:21:53 by lcuevas-          #+#    #+#             */
/*   Updated: 2023/10/02 14:46:30 by lcuevas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	ft_memset(s, 0, n);
}

/* void	ft_bzero(void *s, size_t n)
{
	size_t			i;
	unsigned char	*voidptr;

	i = 0;
	voidptr = (unsigned char *)s;
	while (i < n)
	{
		voidptr[i] = 0;
		i += 1;
	}
} */

/*
mete nulos en un string n posiciones.
hay que hacer casting al string para que vaya bite a bite
#include <stdio.h>

int	main(void)
{
	char str[] = "stringstringstringstring";
	
	ft_bzero(str, 5);
	printf("%s", str);
	return(0);
}
*/