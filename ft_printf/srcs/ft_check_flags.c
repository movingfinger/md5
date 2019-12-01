/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_flags.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sako <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/30 22:23:06 by sako              #+#    #+#             */
/*   Updated: 2019/07/30 22:23:07 by sako             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	o_space(t_format *form, int len, char **front, char **space)
{
	int		size;

	if (form->prec && (form->prec >= len))
		size = form->width - form->prec;
	else
		size = form->width - len;
	*front = ft_memalloc_specific('0', (form->prec) ? form->prec - len : 0);
	if (!*front)
		*front = ft_memalloc_specific('\0', 1);
	if (ft_strchr(form->flag, '0') && form->mflag == 0 && form->pnull)
		*space = ft_memalloc_specific('0', size);
	else
		*space = ft_memalloc_specific(' ', size);
	if (!*space)
		*space = ft_memalloc_specific('\0', 1);
}

char	*check_flag_width_octal(t_format *form, int len, char *str)
{
	char		*sign;
	char		*res;
	char		*front;
	char		*space;

	len = ft_strlen(str);
	if (form->fnull && form->wnull && form->pnull && form->prec)
		return (str);
	sign = ft_strdup("");
	form->prec = (form->pnull || form->prec == -2) ? 0 : form->prec;
	o_space(form, len, &front, &space);
	if ((form->mflag == 1) && !form->pnull)
		res = ft_strjoin_new4(sign, front, str, space);
	else if ((form->mflag == 1) && form->pnull)
		res = ft_strjoin_new4(front, sign, str, space);
	else if (form->pnull && ft_strchr(form->flag, '0'))
		res = ft_strjoin_new4(front, sign, space, str);
	else if (form->pnull)
		res = ft_strjoin_new4(front, space, sign, str);
	else if (form->width < form->prec)
		res = ft_strjoin_new4(sign, front, str, space);
	else
		res = ft_strjoin_new4(space, sign, front, str);
	return (res);
}

void	p_space(t_format *form, char **space, int len, char **res)
{
	int		size;

	size = (!form->prec) ? len : form->prec - 2;
	*space = ft_memalloc_specific(' ', form->width - size - 2);
	if (*space && !form->fnull && form->mflag == 1)
		*res = ft_strjoin_new(*res, *space);
	else if (space)
		*res = ft_strjoin_new(*space, *res);
}

char	*check_flag_width_pointer(t_format *form, int len, char *str)
{
	char	*res;
	char	*zero;
	char	*space;

	res = ft_strdup(str);
	len = ft_strlen(res);
	zero = NULL;
	form->width = (form->width < form->prec) ? 0 : form->width;
	form->prec = (form->prec <= len) ? 0 : form->prec;
	if (!ft_strchr(form->flag, '0'))
		zero = ft_memalloc_specific('0', (form->prec - len));
	else if (form->mflag == 0)
		zero = ft_memalloc_specific('0', (form->width - len));
	res = (!zero ? res : ft_strjoin_new(zero, res));
	len = ft_strlen(res);
	res = ft_strjoin_free_end("0x", res);
	if (form->width)
		p_space(form, &space, len, &res);
	ft_strdel(&str);
	return (res);
}
