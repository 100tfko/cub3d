/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcuevas- <lcuevas-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 18:49:31 by lcuevas-          #+#    #+#             */
/*   Updated: 2023/10/02 14:56:20 by lcuevas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;

	i = 0;
	if (dstsize == 0)
		return (ft_strlen(src));
	while (src[i] != '\0' && i < (dstsize - 1))
	{
		dst [i] = src [i];
		i += 1;
	}
	dst [i] = 0;
	return (ft_strlen(src));
}

/*
hace copia, garantiza nulo y devuelve longitud para que compruebes

int	main(void)
{
	char			dest[5];
	char			src[] = "string";
	unsigned int	size;
	unsigned int	count;

	size = 5;
	ft_strlcpy(dest, src, size);
	return (0);
}*/