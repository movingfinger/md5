/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sako <sako@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/01 21:05:12 by sako              #+#    #+#             */
/*   Updated: 2019/05/08 19:51:54 by sako             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	Extract the string by size len. We start from 0 to len.
*/

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*res;
	size_t	i;

	i = 0;
	if (!s || start > ft_strlen(s) || (int)len < 0)
		return (NULL);
	res = ft_strnew(len);
	if (!res)
		return (NULL);
	while (len > i)
		res[i++] = s[start++];
	res[i] = '\0';
	return (res);
}

/*
**	Extract the string by size len. We start from 0 to len.
**	We free the input string s.
*/

char	*ft_strsub_new(char *s, unsigned int start, size_t len)
{
	char	*res;
	size_t	i;

	i = 0;
	if (!s || start > ft_strlen(s) || (int)len < 0)
		return (NULL);
	res = ft_strnew(len);
	if (!res)
		return (NULL);
	while (len > i)
		res[i++] = s[start++];
	res[i] = '\0';
	if (s)
		free(s);
	return (res);
}

/*
**	Extract the string by size len. We start from len to 0.
**	We free the input string s.
*/

char	*ft_strsub_end_new(char *s, unsigned int end, size_t len)
{
	char	*res;
	size_t	i;

	i = len;
	if (!s || end < ft_strlen(s) || (int)len < 0)
		return (NULL);
	res = ft_strnew(len);
	if (!res)
		return (NULL);
	while (i)
		res[--i] = s[--end];
	res[len] = '\0';
	if (s)
		free(s);
	return (res);
}
