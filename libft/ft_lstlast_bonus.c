/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcuevas- <lcuevas-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 13:22:29 by lcuevas-          #+#    #+#             */
/*   Updated: 2023/10/03 13:20:51 by lcuevas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	t_list	*cplst;

	if (lst == 0)
		return (0);
	cplst = lst;
	while (cplst->next != 0)
		cplst = cplst->next;
	return (cplst);
}

/*
recorre lista y devuelve el último nodo
*/