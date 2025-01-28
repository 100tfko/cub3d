/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcuevas- <lcuevas-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 12:50:31 by lcuevas-          #+#    #+#             */
/*   Updated: 2023/10/05 11:29:39 by lcuevas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*ptr;

	ptr = (unsigned char *)s;
	c = (unsigned char)c;
	while (n != 0)
	{
		if (*ptr == c)
			return ((void *)ptr);
		ptr += 1;
		n -= 1;
	}
	return (0);
}
/*
busca c y devuelve puntero. pero ahora byte a byte
antes tenia puesto 	while (ptr != 0 && n != 0), pero protege "demasiado"
*/