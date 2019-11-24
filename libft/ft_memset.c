/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sako <sako@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/29 13:26:04 by sako              #+#    #+#             */
/*   Updated: 2019/05/08 22:36:21 by sako             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*res;

	if (len == 0)
		return (b);
	res = (unsigned char *)b;
	while (len--)
		*res++ = (unsigned char)c;
	*res = 0;
	return (b);
}
