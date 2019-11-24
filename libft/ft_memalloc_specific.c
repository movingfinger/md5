/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc_specific.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sako <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/11 00:49:25 by sako              #+#    #+#             */
/*   Updated: 2019/08/11 00:49:26 by sako             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc_specific(int c, size_t size)
{
	void	*s;

	if (size == 0)
		return (NULL);
	s = (void *)malloc(sizeof(void) * (size));
	if (!s)
		return (NULL);
	ft_memset(s, c, size);
	return (s);
}
