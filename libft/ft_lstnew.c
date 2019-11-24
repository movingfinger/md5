/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sako <sako@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/04 21:11:13 by sako              #+#    #+#             */
/*   Updated: 2019/05/04 22:37:37 by sako             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Allocates (with malloc(3)) and returns a “fresh” link. The variables
** content and content_size of the new link are ini- tialized by copy
** of the parameters of the function. If the pa- rameter content is nul,
** the variable content is initialized to NULL and the variable
** content_size is initialized to ** 0 even if the parameter content_size
** isn’t. The variable next is initialized to NULL. If the allocation
** fails, the function returns NULL.
**typedef struct		s_list
**{
**	void			*content;
**	size_t			content_size;
**	struct s_list	*next;
**}					t_list;
*/

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*new;

	if (!(new = (t_list *)malloc(sizeof(t_list))))
		return (NULL);
	if (content == NULL)
	{
		new->content = NULL;
		new->content_size = 0;
	}
	else
	{
		new->content = malloc(sizeof(content));
		if (!new->content)
		{
			free(new);
			return (NULL);
		}
		ft_memcpy(new->content, content, content_size);
		new->content_size = content_size;
	}
	new->next = NULL;
	return (new);
}
