/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sako <sako@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/04 23:46:04 by sako              #+#    #+#             */
/*   Updated: 2019/05/05 00:17:53 by sako             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** 1. Iterates a list lst and applies the function f
** to each link to create a “fresh” list (using malloc(3))
** resulting from the suc- cessive applications of f.
** 2. If the allocation fails, the function returns NULL.
*/

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*list;
	t_list	*new;

	if (!lst)
		return (NULL);
	list = f(lst);
	new = list;
	while (lst->next)
	{
		lst = lst->next;
		if (!(list->next = f(lst)))
		{
			free(list->next);
			return (NULL);
		}
		list = list->next;
	}
	return (new);
}
