/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_flag_char.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sako <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/02 14:39:25 by sako              #+#    #+#             */
/*   Updated: 2019/09/02 14:39:27 by sako             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*check_flag_width_char(t_format *form, int len, char *str)
{
	char	*res;
	char	*space;

	res = ft_strdup(str);
	space = NULL;
	if (form->width != 0 || form->prec != -1)
	{
		if (!form->prec)
			str = ft_memset(str, 0, sizeof(char) * ft_strlen(str));
		else if (form->prec != -1 && form->prec != -2)
			str = ft_strsub_new(str, 0, form->prec);
		len = (len && form->prec != -1) ? form->prec : len;
		if (form->width > 0)
		{
			form->width += (form->pnull) ? -1 : 0;
			space = ft_strnew(form->width - len);
			space = ft_memset(space, ' ', form->width - len);
		}
		if (form->flag == NULL && !form->mflag && space)
			res = ft_strjoin_new(space, str);
		else if (form->mflag && space)
			res = ft_strjoin_new(str, space);
	}
	return (res);
}

char	*check_flag_width_string(t_format *form, int len, char *str)
{
	char	*res;
	char	*space;

	res = ft_strdup(str);
	len = ft_strlen(res);
	if (form->prec != -1 && form->prec < len)
		res = ft_strsub_new(res, 0, form->prec);
	else
		form->prec = len;
	if (form->width)
	{
		space = ft_memalloc_specific((ft_strchr(form->flag, '0') ? '0' : ' ')\
		, (form->width - ((form->prec <= 0) ? 0 : form->prec)));
		if (!form->fnull && form->mflag == 1)
			res = ft_strjoin_new(res, space);
		else if (space)
			res = ft_strjoin_new(space, res);
	}
	return (res);
}

char	*check_flag_width_percent(t_format *form, char *str)
{
	char *res;
	char *space;

	res = ft_strdup(str);
	form->prec = 1;
	if (form->width)
	{
		space = ft_memalloc_specific((ft_strchr(form->flag, '0') && !form->mflag
		? '0' : ' '), (form->width - ((form->prec <= 0) ? 0 : form->prec)));
		if (!form->fnull && form->mflag == 1)
			res = ft_strjoin_new(res, space);
		else if (space)
			res = ft_strjoin_new(space, res);
	}
	ft_strdel(&str);
	return (res);
}
