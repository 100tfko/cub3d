/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcuevas- <lcuevas-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 13:39:12 by lcuevas-          #+#    #+#             */
/*   Updated: 2023/10/03 13:59:25 by lcuevas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*cplst;

	if (*lst != 0)
	{
		cplst = ft_lstlast(*lst);
		cplst->next = new;
	}
	else
		*lst = new;
}

/*
recorre lista hasta el final y añade un nodo
si no hay nodos pues lo añade igual
*/