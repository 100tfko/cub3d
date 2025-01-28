/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcuevas- <lcuevas-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 12:52:38 by lcuevas-          #+#    #+#             */
/*   Updated: 2023/10/03 13:17:34 by lcuevas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	ft_lstadd_front(t_list **lst, t_list*new)
{
	if (lst != 0 && new != 0)
	{
		new->next = *lst;
		*lst = new;
	}
}

/*
añade un nodo al inicio de la lista
el primer puntero de la lista ahroa es new
*/