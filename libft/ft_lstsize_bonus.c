/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcuevas- <lcuevas-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 13:04:45 by lcuevas-          #+#    #+#             */
/*   Updated: 2023/10/03 13:17:50 by lcuevas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int		n;
	t_list	*cplst;

	if (lst == 0)
		return (0);
	n = 1;
	cplst = lst;
	while (cplst->next != 0)
	{
		n += 1;
		cplst = cplst->next;
	}
	return (n);
}

/*
recorre la lista y cuenta nodos
*/