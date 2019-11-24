/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ftoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sako <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/07 00:00:05 by sako              #+#    #+#             */
/*   Updated: 2019/08/07 00:00:10 by sako             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

intmax_t	ft_floatlen(long double num, int flen)
{
	intmax_t		len;
	intmax_t		ipart;

	len = 0;
	if (num < 0 && flen)
	{
		num = -num;
		++len;
	}
	ipart = (intmax_t)num;
	len += check_signed_num_len(ipart);
	if (flen != -2 && flen)
		len += (flen + 1);
	return (len);
}

/*
** It is just remedy for check rounding. I need to find better way to
** fix this round up problem...
** Get rid of random generated number from bottom
*/

void		check_round(intmax_t *ipart, long double *fpart, int flen)
{
	int				i;
	long double		check_round;
	long double		temp;

	i = -1;
	check_round = *fpart;
	flen = (flen == -2) ? 0 : flen;
	while (++i < flen + 1)
	{
		check_round -= (int)check_round;
		check_round = check_round * 10;
	}
	if (check_round >= 5)
	{
		temp = ft_powf((long double)0.1, flen);
		temp -= temp * 0.1;
		*fpart += temp;
	}
	if (*fpart > 1)
	{
		*ipart = (*ipart > 0) ? *ipart + 1 : *ipart - 1;
		*fpart -= 1;
	}
}

char		*store_int(intmax_t ipart, int neg)
{
	char	*str_int;

	str_int = (ipart == 0 && neg == 1) ? ft_strdup("-0") : ft_itoa(ipart);
	return (str_int);
}

char		*store_float(char *str_int, long double fpart, int len, int flen)
{
	int		i;
	char	*str_float;
	char	*result;

	i = 0;
	str_float = ft_strnew(flen);
	if (flen != -2)
		str_float[i++] = '.';
	while (flen != -2 && (i < flen + 1))
	{
		fpart *= 10.0;
		str_float[i++] = (int)fpart + '0';
		fpart -= (int)fpart;
	}
	if (flen != -2)
		result = ft_strjoin_new(str_int, str_float);
	else
		result = ft_strjoin_free_front(str_int, str_float);
	len = (len == 0 && flen == -2) ? 1 : len;
	result[len] = '\0';
	return (result);
}

char		*ft_ftoa(long double num, int flen)
{
	char			*str;
	int				len;
	int				neg;
	intmax_t		ipart;
	long double		fpart;

	len = ft_floatlen(num, flen);
	neg = (num >= 0) ? 0 : 1;
	num = (neg == 1) ? -num : num;
	ipart = num;
	fpart = num - (long double)ipart;
	ipart = (neg == 1) ? -ipart : ipart;
	check_round(&ipart, &fpart, flen);
	str = store_int(ipart, neg);
	str = store_float(str, fpart, len, flen);
	return (str);
}
