/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcuevas- <lcuevas-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 11:06:09 by lcuevas-          #+#    #+#             */
/*   Updated: 2024/01/11 11:10:20 by lcuevas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	unsigned int	i;
	unsigned int	j;

	if (*needle == 0)
		return ((char *)haystack);
	i = 0;
	while (haystack[i] != 0 && (size_t)i < len)
	{
		j = 0;
		while ((haystack[i + j] == needle[j]) && (size_t)i + j < len)
		{
			j += 1;
			if (needle[j] == 0)
				return ((char *)&haystack[i]);
		}
		i += 1;
	}
	return (0);
}
