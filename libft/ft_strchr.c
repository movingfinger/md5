/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sako <sako@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/30 14:41:12 by sako              #+#    #+#             */
/*   Updated: 2019/05/03 14:22:21 by sako             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	Check if string s hac character c in any place.
**	Return the c position if available. Other than that, return NULL.
*/

char	*ft_strchr(const char *s, int c)
{
	char	*res;
	int		len;

	res = (char *)s;
	len = (!s) ? 0 : ft_strlen(res);
	if (!res)
		return (res);
	while (len-- >= 0)
	{
		while (*res == c)
			return (res);
		res++;
	}
	return (NULL);
}
