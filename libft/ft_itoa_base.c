/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sako <sako@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/26 01:09:12 by sako              #+#    #+#             */
/*   Updated: 2019/07/27 06:02:27 by sako             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int				ft_nbrlen_signed(long long int nbr, int base)
{
	int		len;

	len = 0;
	if (nbr == 0)
		return (1);
	if (nbr < 0)
		++len;
	while (nbr != 0)
	{
		nbr /= base;
		++len;
	}
	return (len);
}

char					*ft_itoa_base_signed(long long int nbr, int base)
{
	char	*str;
	int		len;
	int		tmp;
	int		neg;

	neg = 0;
	if (nbr < 0)
		if (base == 10)
			neg = 1;
	len = ft_nbrlen_signed(nbr, base);
	if (!(str = ft_memalloc_specific('0', len)))
		return (NULL);
	while (len-- > 0)
	{
		tmp = (nbr % base);
		tmp = (tmp < 0) ? -tmp : tmp;
		*(str + len) = tmp + ((tmp > 9) ? 'A' - 10 : '0');
		nbr /= base;
	}
	if (neg)
		*(str) = '-';
	return (str);
}

static int				ft_nbrlen_unsigned(uintmax_t nbr, int base)
{
	int		len;

	len = 0;
	if (nbr == 0)
		return (1);
	while (nbr > 0)
	{
		nbr /= base;
		len++;
	}
	return (len);
}

char					*ft_itoa_base_unsigned(uintmax_t nbr, int base)
{
	char	*str;
	size_t	len;

	len = ft_nbrlen_unsigned(nbr, base);
	if (!(str = ft_strnew(len)))
		return (NULL);
	while (len-- > 0)
	{
		*(str + len) = (nbr % base) + ((nbr % base > 9) ? 'A' - 10 : '0');
		nbr /= base;
	}
	return (str);
}
