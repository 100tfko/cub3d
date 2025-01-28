/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcuevas- <lcuevas-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 13:08:42 by lcuevas-          #+#    #+#             */
/*   Updated: 2023/10/02 15:12:02 by lcuevas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*ptr1;
	unsigned char	*ptr2;

	ptr1 = (unsigned char *)s1;
	ptr2 = (unsigned char *)s2;
	if (n <= 0)
		return (0);
	while (n > 1 && *ptr1 == *ptr2)
	{
		ptr1 += 1;
		ptr2 += 1;
		n -= 1;
	}
	if (n > 0 && *ptr1 != *ptr2)
		return (*ptr1 - *ptr2);
	else
		return (0);
}

/*
compara n bytes y devuelve diferencia si hay alguna.
*/