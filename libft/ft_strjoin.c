/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcuevas- <lcuevas-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 16:13:02 by lcuevas-          #+#    #+#             */
/*   Updated: 2023/10/09 10:12:07 by lcuevas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>
#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*new;
	int		i;
	int		j;

	i = (ft_strlen(s1) + ft_strlen (s2) + 1);
	new = malloc (sizeof(char) * (i));
	if (new == 0)
		return (0);
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
	return (new);
}
/*
reserva espacio y concatena
*/