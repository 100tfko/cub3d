/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcuevas- <lcuevas-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 15:26:46 by lcuevas-          #+#    #+#             */
/*   Updated: 2023/10/03 13:27:50 by lcuevas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*cplst;

	if (lst != 0 && del != 0)
	{
		while (*lst != 0)
		{
			cplst = (*lst)->next;
			ft_lstdelone(*lst, del);
			(*lst) = cplst;
		}
	}
}

/*
elimina el nodo y todosl os siguientes
*/