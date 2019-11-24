/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sako <sako@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/30 13:04:33 by sako              #+#    #+#             */
/*   Updated: 2019/05/08 20:39:57 by sako             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t		i;
	size_t		j;
	size_t		n;
	size_t		dlen;

	i = 0;
	j = 0;
	n = dstsize;
	while (n-- != 0 && dst[i] != '\0')
		i++;
	dlen = i;
	n = dstsize - dlen;
	if (n == 0)
		return (dlen + ft_strlen(src));
	while (src[j] != '\0')
	{
		if (n != 1)
		{
			dst[i++] = src[j];
			n--;
		}
		j++;
	}
	dst[i] = '\0';
	return (dlen + j);
}
