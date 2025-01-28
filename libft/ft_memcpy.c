/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcuevas- <lcuevas-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 15:14:59 by lcuevas-          #+#    #+#             */
/*   Updated: 2023/10/05 11:23:33 by lcuevas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char		*d;
	const char	*s;
	size_t		i;

	if (dst == 0 && src == 0)
		return (dst);
	d = (char *)dst;
	s = (const char *)src;
	i = 0;
	while (i < n)
	{
		d[i] = s[i];
		i += 1;
	}
	return (dst);
}
/*
copia un string sobre el dst

#include <stdio.h>

int	main(void)
{
	char dst[] = "stringstringstringstring";
	char src[] = "nonononononono";
	
	printf("%s\n", ft_memcpy(dst, src, 5));
	printf("%s\n", memcpy(dst, src, 5));
	return(0);
}
*/