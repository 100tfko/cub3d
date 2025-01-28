/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcuevas- <lcuevas-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 10:51:38 by lcuevas-          #+#    #+#             */
/*   Updated: 2023/10/02 14:43:53 by lcuevas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memset(void *b, int c, size_t len)
{
	size_t	i;

	i = 0;
	while (i < len)
	{
		((char *)b)[i] = c;
		i += 1;
	}
	return (b);
}
/*
llena el strings de "c" len veces
le "asigno" una tipo al void así rapido fijo
esto es porque al llegarme void lo tengo que "castear"*/

/*#include <stdio.h>

int	main(void)
{
	char str[] = "stringstringstringstring";
	
	ft_memset(str, '.', 5);
	printf("%s", str);
	return(0);
}
*/
/* tengoque "darle formato" al void. Lo puedo hacer a lo burro
o con un puntero flotante que ya segun condiciones voy asignando como:
	unsigned char	*voideptr;
	voidptr = (unsigned char *)b  */