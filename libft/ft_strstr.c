/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sako <sako@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/30 15:37:56 by sako              #+#    #+#             */
/*   Updated: 2019/05/05 16:46:08 by sako             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	int		i;
	int		j;
	char	*s;

	i = 0;
	j = 0;
	s = (char *)haystack;
	while (s[j])
	{
		i = 0;
		while (s[j] && s[j] == needle[i])
		{
			j++;
			if (needle[i])
				i++;
		}
		if (needle[i] == '\0')
			return (&(s[j - ft_strlen(needle)]));
		j = j - i + 1;
	}
	if (needle[i] == '\0' && s[j] == needle[i])
		return (s);
	return (NULL);
}
