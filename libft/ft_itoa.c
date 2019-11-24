/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sako <sako@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/01 10:25:47 by sako              #+#    #+#             */
/*   Updated: 2019/07/29 03:20:19 by sako             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_itoa(long long int nbr)
{
	char	*s;
	int		length;
	int		i;

	if (nbr == -2147483648)
		return (ft_strdup("-2147483648"));
	i = 0;
	length = check_signed_num_len(nbr);
	i = length;
	if (!(s = (char *)malloc(sizeof(char) * (length + 1))))
		return (NULL);
	else if (nbr < 0)
	{
		s[0] = '-';
		nbr = nbr * -1;
	}
	else if (nbr == 0)
		s[0] = '0';
	while (nbr > 0)
	{
		s[--length] = nbr % 10 + '0';
		nbr /= 10;
	}
	s[i] = '\0';
	return (s);
}
