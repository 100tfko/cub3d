/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcuevas- <lcuevas-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 15:52:14 by lcuevas-          #+#    #+#             */
/*   Updated: 2023/10/02 14:37:33 by lcuevas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

size_t	ft_strlen(const char *str)
/*en el maual pone sizet y const char, ver eso*/
{
	int	number;

	number = 0;
	while (str [number] != '\0')
		number += 1;
	return (number);
}
/*
mide longitud de string en chars (+ el \0 por el tema posición 0)
#include <stdio.h>

int	main(void)
{
	char	*str;
	
	str = "string";
	printf("%d\n", ft_strlen(str));
	printf("%d\n", strlen(str));
	return(0);
}
*/
