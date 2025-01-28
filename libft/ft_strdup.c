/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcuevas- <lcuevas-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 13:17:03 by lcuevas-          #+#    #+#             */
/*   Updated: 2023/10/02 15:16:46 by lcuevas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*cpy;
	size_t	len;

	len = ft_strlen(s1) + 1;
	cpy = (char *)malloc(sizeof(*cpy) * (len));
	if (cpy == 0)
		return (0);
	return ((char *)ft_memcpy(cpy, s1, len));
}

/*
asigna espacio de memoria y despues hace la copia

#include <stdio.h>

int	main(void)
{
	char	str[] = "stringstring";
	char	cpy[];

	cpy = ft_strdup(str);
	prinf("%s\n", cpy);
	return (0);
}*/