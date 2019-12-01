/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_floatformat.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sako <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/03 22:19:55 by sako              #+#    #+#             */
/*   Updated: 2019/12/01 11:03:55 by sako             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_float(t_format *form, va_list args)
{
	int			len;
	int			width;
	int			prec;
	char		*res;
	long double	temp;

	temp = convert2float(form, args);
	width = form->width;
	prec = (form->prec != -1) ? form->prec : 6;
	len = ft_floatlen(temp, prec);
	res = ft_ftoa(temp, prec);
	if ((prec == -2 || prec == 0) && ft_strchr(form->flag, '#'))
		res = ft_strjoin_free_front(res, ".");
	else
		res = check_flag_width_float(form, len, width, res);
	return (res);
}
