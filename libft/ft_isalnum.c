/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcuevas- <lcuevas-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 12:08:37 by lcuevas-          #+#    #+#             */
/*   Updated: 2023/10/02 14:27:36 by lcuevas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalnum(int c)
{
	if (ft_isalpha(c) || ft_isdigit(c))
		return (1);
	else
		return (0);
}
/* 
comprueba si es alfadigit

#include <stdio.h>
#include <ctype.h>

int	main(void)
{
	char	c;

	c = 'f';
	printf ("%d\n", ft_isalnum(c));
	printf ("%d\n", isdalnum(c));
	return (0);
}
*/
