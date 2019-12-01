/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_binaryformat.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sako <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 15:57:28 by sako              #+#    #+#             */
/*   Updated: 2019/12/01 11:01:17 by sako             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*binary(t_format *form, va_list args)
{
	int			len;
	char		*res;
	uintmax_t	temp;

	temp = convert2u_int(form, args);
	len = check_signed_num_len(temp);
	res = ft_itoa_base_unsigned(temp, 2);
	if (((form->pnull && form->prec == 0) || (form->prec == -2 &&\
	!form->pnull)) && !ft_strcmp(res, "0"))
		res = ft_strdup("");
	if (form->flag && ft_strchr(form->flag, '#') && ft_strcmp(res, "0"))
		res = ft_strjoin_free_end("0", res);
	res = check_flag_width_octal(form, len, res);
	return (res);
}
