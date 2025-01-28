/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcuevas- <lcuevas-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 11:55:37 by lcuevas-          #+#    #+#             */
/*   Updated: 2024/02/09 11:39:38 by lcuevas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static int	ft_wordcnt(char const *s, char c)
{
	int		n;

	n = 0;
	while (*s != 0)
	{
		if (*s != c)
		{
			n += 1;
			while (*s != 0 && *s != c)
				s += 1;
		}
		else
			s += 1;
	}
	return (n);
}

static int	ft_wordln(char	const *s, char c, int i)
{
	int	ln;

	ln = 0;
	while (s[i] != 0 && s[i] != c)
	{
		ln += 1;
		i += 1;
	}
	return (ln);
}

static void	ft_free(char **arr, int j)
{
	while (j-- > 0)
		free(arr[j]);
	free(arr);
}

char	**ft_split(char const *s, char c)
{
	char	**arr;
	int		i;
	int		j;

	i = 0;
	j = 0;
	arr = (char **)malloc((ft_wordcnt(s, c) + 1) * sizeof(char *));
	if (arr == 0)
		return (0);
	while (j < ft_wordcnt(s, c))
	{
		while (s[i] == c)
			i += 1;
		arr[j] = ft_substr(s, i, ft_wordln(s, c, i));
		if (arr[j] == 0)
		{
			ft_free(arr, j);
			return (0);
		}
		i += (int)ft_wordln(s, c, i);
		j += 1;
	}
	arr[j] = 0;
	return (arr);
}

/*
haceu na matriz dividiendo un string en otros string segun c
preguntara Elisa por los print para comprobar en un while

int	main(void)
{
	char	*str;
	char	c;
	char	**arr;

	str = malloc(1000);
	*str = "stringstringstringstringstringstringstringstringstring";
	c = n;
	printf("%s\n", str);
	arr = ft_split(str, c);
	printf("%s\n", arr[1]);
	free(arr);
	return (0);
}
*/