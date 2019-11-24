/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sako <sako@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/30 23:33:17 by sako              #+#    #+#             */
/*   Updated: 2019/06/13 20:43:41 by sako             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char	*csrc;
	char	*cdest;
	size_t	i;

	i = -1;
	csrc = (char *)src;
	cdest = (char *)dest;
	if (dest == NULL && src == NULL)
		return (dest);
	if (csrc < cdest)
		while ((int)(--n) >= 0)
			cdest[n] = csrc[n];
	else
		while (n > ++i)
			cdest[i] = csrc[i];
	return (dest);
}
