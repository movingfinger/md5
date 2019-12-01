/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_intformat.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sako <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/30 22:17:59 by sako              #+#    #+#             */
/*   Updated: 2019/07/30 22:18:00 by sako             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*u_integer(t_format *form, va_list args)
{
	int			len;
	char		*res;
	uintmax_t	temp;

	temp = convert2u_int(form, args);
	res = ft_itoa_base_unsigned(temp, 10);
	len = ft_strlen(res);
	res = check_flag_width_unsigned(form, res);
	return (res);
}

char	*s_integer(t_format *form, va_list args)
{
	int				len;
	char			*res;
	long long int	temp;

	if (form->width < 0)
	{
		form->width *= -1;
		form->flag = ft_strdup("-");
	}
	temp = convert2s_int(form, args);
	len = check_signed_num_len(temp);
	res = ft_itoa_base_signed(temp, 10);
	res = check_flag_width_signed(form, len, res);
	return (res);
}

char	*octal(t_format *form, va_list args)
{
	int			len;
	char		*res;
	uintmax_t	temp;

	temp = convert2u_int(form, args);
	len = check_signed_num_len(temp);
	res = ft_itoa_base_unsigned(temp, 8);
	if (((form->pnull && form->prec == 0) || (form->prec == -2 &&\
	!form->pnull)) && !ft_strcmp(res, "0"))
		res = ft_strdup("");
	if (form->flag && ft_strchr(form->flag, '#') && ft_strcmp(res, "0"))
		res = ft_strjoin_free_end("0", res);
	res = check_flag_width_octal(form, len, res);
	return (res);
}

char	*hex_lower(t_format *form, va_list args)
{
	char		*res;
	char		*hex;
	uintmax_t	temp;

	temp = convert2u_int(form, args);
	res = ft_itoa_base_unsigned(temp, 16);
	ft_strtolower(res);
	if (form->fnull && form->wnull && form->pnull && form->prec)
		return (res);
	hex = (form->flag && ft_strchr(form->flag, '#') && temp) ?\
	ft_strdup("0x") : ft_strdup("");
	res = check_flag_width_hex(form, hex, res);
	return (res);
}

char	*hex_upper(t_format *form, va_list args)
{
	char		*res;
	char		*hex;
	uintmax_t	temp;

	temp = convert2u_int(form, args);
	res = ft_itoa_base_unsigned(temp, 16);
	ft_strtoupper(res);
	if (form->fnull && form->wnull && form->pnull && form->prec)
		return (res);
	hex = (form->flag && ft_strchr(form->flag, '#') && temp) ?\
	ft_strdup("0X") : ft_strdup("");
	res = check_flag_width_hex(form, hex, res);
	return (res);
}
