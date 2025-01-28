/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcuevas- <lcuevas-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 11:30:47 by lcuevas-          #+#    #+#             */
/*   Updated: 2023/10/02 15:07:04 by lcuevas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strchr(const char *s, int c)
{
	while (*s != 0)
	{
		if (*s == (unsigned char)c)
			return ((char *)s);
		s += 1;
	}
	if ((unsigned char)c == 0)
		return ((char *)s);
	return (0);
}

/*
busca c y devuelve puntero a la posición de c en string

#include <stdio.h>

int	main(void)
{
    char	*str;
    char	c;
    char	*ptr;
    
    str = "string";
    c = 0;
    ptr = ft_strchr(str, c);
    printf("%s\n", str);
    printf("%s\n", ptr);
    
    return (0);
}
*/