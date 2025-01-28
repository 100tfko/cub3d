/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcuevas- <lcuevas-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 13:32:51 by lcuevas-          #+#    #+#             */
/*   Updated: 2023/10/03 13:51:08 by lcuevas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*newlist;
	t_list	*cplst;
	void	*aux;

	if (lst == 0)
		return (0);
	newlist = 0;
	while (lst != 0)
	{
		aux = f(lst->content);
		cplst = ft_lstnew(aux);
		if (cplst != 0)
		{
			ft_lstadd_back(&newlist, cplst);
			lst = lst->next;
		}
		else
		{
			ft_lstclear(&newlist, del);
			del(aux);
			return (0);
		}
	}
	return (newlist);
}
