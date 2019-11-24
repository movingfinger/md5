/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp_index.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sako <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/23 23:59:24 by sako              #+#    #+#             */
/*   Updated: 2019/07/24 03:21:04 by sako             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	return -1 if string s is null, return -2 if there is no matching with
**	character c in string s. return any index after we find matching.
*/

int		ft_strcmp_index(const char *s, char c)
{
	char	*res;
	int		len;
	int		i;

	i = -1;
	res = (char *)s;
	len = ft_strlen(res);
	if (!res || !c)
		return (-1);
	while (len-- >= 0)
	{
		while (res[++i] == c)
			return (i);
		res++;
	}
	return (-2);
}
