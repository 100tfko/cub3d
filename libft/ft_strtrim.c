/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcuevas- <lcuevas-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 11:01:36 by lcuevas-          #+#    #+#             */
/*   Updated: 2024/01/11 11:10:56 by lcuevas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	int		start;
	int		end;
	char	*trim;

	if (s1 == 0 || set == 0)
		return (0);
	start = 0;
	end = ft_strlen(s1) -1;
	while (ft_strchr(set, s1[start]) != 0 && start <= end)
		start += 1;
	if (start > end)
		return (ft_strdup(s1 + end + 1));
	while (ft_strchr(set, s1[end]) != 0 && end >= start)
		end -= 1;
	trim = malloc(end - start + 2);
	if (trim == 0)
		return (0);
	ft_strlcpy(trim, &s1[start], end - start + 2);
	return (trim);
}
