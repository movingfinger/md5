/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sako <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/30 22:26:58 by sako              #+#    #+#             */
/*   Updated: 2019/07/30 22:27:00 by sako             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

uintmax_t	convert2u_int(t_format *form, va_list args)
{
	const char	*length;
	uintmax_t	temp;

	temp = va_arg(args, uintmax_t);
	length = form->length;
	if (length != NULL)
	{
		if (!(ft_strcmp(length, "hh")))
			temp = (unsigned char)temp;
		else if (!(ft_strcmp(length, "h")))
			temp = (unsigned short)temp;
		else if (!(ft_strcmp(length, "l")))
			temp = (unsigned long)temp;
		else if (!(ft_strcmp(length, "ll")))
			temp = (unsigned long long)temp;
		else if (!(ft_strcmp(length, "j")))
			temp = (uintmax_t)temp;
	}
	else
		temp = (unsigned int)temp;
	return (temp);
}

intmax_t	convert2s_int(t_format *form, va_list args)
{
	const char		*length;
	long long int	temp;

	temp = va_arg(args, long long int);
	length = form->length;
	if (length != NULL)
	{
		if (!(ft_strcmp(length, "hh")))
			temp = (char)temp;
		else if (!(ft_strcmp(length, "h")))
			temp = (short)temp;
		else if (!(ft_strcmp(length, "l")))
			temp = (long)temp;
		else if (!(ft_strcmp(length, "ll")))
			temp = (long long int)temp;
		else if (!(ft_strcmp(length, "j")))
			temp = (intmax_t)temp;
	}
	else
		temp = (int)temp;
	return (temp);
}

long double	convert2float(t_format *form, va_list args)
{
	long double temp;

	if (form->length != NULL && !(ft_strcmp(form->length, "L")))
		temp = va_arg(args, long double);
	else
		temp = va_arg(args, double);
	return (temp);
}
