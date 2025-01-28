/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcuevas- <lcuevas-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 18:38:00 by lcuevas-          #+#    #+#             */
/*   Updated: 2023/10/02 14:53:22 by lcuevas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	const unsigned char	*s;
	unsigned char		*d;

	if (!dst && !src)
		return (dst);
	if (dst < src)
		return (ft_memcpy(dst, src, len));
	s = (unsigned char *)src;
	d = (unsigned char *)dst;
	while (len--)
		d[len] = s[len];
	return (dst);
}

/*
como el copy pero en orden inverso
por el solapamiento de memoria

#include <stdio.h>

int	main(void)
{
	char dst[] = "stringstringstringstring";
	char src[] = "nonononononono";
	
	ft_memmove(dst, src, 5);
	printf("%s", ft_memmove(dst, src, 5);
	printf("%s", ft_memmove(dst, src, 5);
	return(0);
}
*/