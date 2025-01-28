/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcuevas- <lcuevas-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 13:24:54 by lcuevas-          #+#    #+#             */
/*   Updated: 2023/10/02 15:00:14 by lcuevas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while ((dst[i] != 0) && i < dstsize)
		i += 1;
	while ((src[j] != 0) && (i + j + 1) < dstsize)
	{
		dst[i + j] = src[j];
		j += 1;
	}
	if (i < dstsize)
		dst[i + j] = 0;
	return (i + ft_strlen(src));
}

/*
concatena y devuelve longitud de lo que ha intentado crear

#include <stdio.h>

int	main(void)
{
	char	dst[] = "stringstring                    ";
	char	src[] = "nonono";
	int		dstsize;
	int		ret;

	dstsize = 20;
	ret = ft_strlcat(dst, src, dstsize);
	printf("%s", dst);
	printf("%d", dstsize);
	printf("%d", ret);
	return (0);
}*/

/*seguro contra size 0 o dst mas corto?*/
