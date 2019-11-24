/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sako <sako@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/30 21:35:36 by sako              #+#    #+#             */
/*   Updated: 2019/06/13 20:42:28 by sako             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*csrc;
	unsigned char	*cdest;
	int				i;

	i = 0;
	csrc = (unsigned char *)src;
	cdest = (unsigned char *)dest;
	if (dest == NULL && src == NULL)
		return (dest);
	while (n--)
	{
		cdest[i] = csrc[i];
		i++;
	}
	return (cdest);
}
