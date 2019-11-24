/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sako <sako@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/01 22:29:05 by sako              #+#    #+#             */
/*   Updated: 2019/05/08 20:08:09 by sako             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strtrim(char const *s)
{
	int		i;
	int		j;
	size_t	k;
	size_t	len;
	char	*res;

	i = 0;
	j = -1;
	k = 0;
	if (!s)
		return (NULL);
	j += ft_strlen(s);
	while (is_whitespace(s[i]))
		i++;
	while (is_whitespace(s[j]) && j)
		j--;
	len = ((j - i + 1) > 0 ? (j - i + 1) : 0);
	if (!(res = ft_strnew(len)))
		return (NULL);
	while (i <= j)
		res[k++] = s[i++];
	res[k] = '\0';
	return (res);
}
