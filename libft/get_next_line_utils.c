/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcuevas- <lcuevas-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 10:13:45 by lcuevas-          #+#    #+#             */
/*   Updated: 2024/01/10 16:52:32 by lcuevas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_challoc(size_t count)
{
	char		*ret;
	size_t		i;

	ret = malloc(count);
	if (ret == NULL)
		return (NULL);
	i = 0;
	while (i < count)
	{
		ret[i] = 0;
		i += 1;
	}
	return (ret);
}

bool	ft_srchnl(char *s)
{
	if (!s)
		return (false);
	while (*s != 0)
	{
		if (*s == '\n')
			return (true);
		s += 1;
	}
	return (false);
}

size_t	gnl_ft_strlen(const char *str)
{
	int	number;

	number = 0;
	while (str [number] != '\0')
		number += 1;
	return (number);
}

char	*gnl_ft_strjoin(char const *s1, char const *s2)
{
	char	*new;
	int		i;
	int		j;

	i = (gnl_ft_strlen(s1) + gnl_ft_strlen (s2) + 1);
	new = malloc (sizeof(char) * (i));
	if (new == 0)
		return (NULL);
	i = 0;
	while (s1[i] != 0)
	{
		new[i] = s1[i];
		i += 1;
	}
	j = 0;
	while (s2[j] != 0)
	{
		new[i] = s2[j];
		i += 1;
		j += 1;
	}
	new[i] = 0;
	return (free((void *)(s1)), new);
}
