/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_flags_int.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sako <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 15:11:56 by sako              #+#    #+#             */
/*   Updated: 2019/09/06 15:11:57 by sako             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	u_space(t_format *form, char **str, char **front, char **space)
{
	int		size;
	int		len;

	len = ft_strlen(*str);
	if (!ft_strcmp(*str, "0") && (!form->prec || form->prec == -2))
	{
		*str = ft_strdup("");
		len = 0;
	}
	form->prec = (form->pnull || form->prec == -2) ? 0 : form->prec;
	size = form->width - ((form->prec && form->prec >= len) ? form->prec : len);
	*front = ft_memalloc_specific('0', (form->prec) ? form->prec - len : 0);
	if (!*front)
		*front = ft_memalloc_specific('\0', 1);
	if (ft_strchr(form->flag, '0') && form->pnull)
		*space = ft_memalloc_specific('0', size);
	else
		*space = ft_memalloc_specific(' ', size);
	if (!*space)
		*space = ft_memalloc_specific('\0', 1);
}

char	*check_flag_width_unsigned(t_format *form, char *str)
{
	char		*sign;
	char		*res;
	char		*front;
	char		*space;

	if (form->fnull && form->wnull && form->pnull && form->prec)
		return (str);
	sign = ft_strdup("");
	u_space(form, &str, &front, &space);
	if (form->mflag == 1 && !form->pnull)
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

int		s_sig_sign(t_format *form, char **sign, char **str, int *sig)
{
	int		len;

	len = ft_strlen(*str);
	if (ft_strchr(form->flag, '+') && ft_atoi(*str) >= 0)
		*sign = ft_strdup("+");
	else if (ft_strchr(form->flag, ' ') && ft_atoi(*str) >= 0)
		*sign = ft_strdup(" ");
	else if (ft_atoi(*str) < 0)
	{
		*str = ft_strsub_end_new(*str, len, len - 1);
		*sign = ft_strdup("-");
	}
	else
	{
		*sign = ft_strdup("");
		*sig = 0;
	}
	len = (ft_strchr(*sign, '-')) ? len - 1 : len;
	if (!ft_strcmp(*str, "0") && (!form->prec || form->prec == -2))
	{
		*str = ft_strdup("");
		len = 0;
	}
	return (len);
}

char	*s_space(t_format *form, int len, int sig, char **space)
{
	int		size;
	char	*front;

	if (form->prec && form->prec >= len)
		size = form->width - (form->prec + sig);
	else
		size = form->width - (len + sig);
	if (form->prec)
		front = ft_memalloc_specific('0', form->prec - len);
	else
		front = ft_memalloc_specific('\0', 1);
	if (form->mflag == 0 && form->pnull && ft_strchr(form->flag, '0'))
		*space = ft_memalloc_specific('0', size);
	else
		*space = ft_memalloc_specific(' ', size);
	if (!*space)
		*space = ft_memalloc_specific('\0', 1);
	return (front);
}

char	*check_flag_width_signed(t_format *form, int len, char *str)
{
	int			sig;
	char		*sign;
	char		*res;
	char		*front;
	char		*space;

	if (form->fnull && form->wnull && form->pnull && form->prec)
		return (str);
	sig = 1;
	len = s_sig_sign(form, &sign, &str, &sig);
	form->prec = (form->pnull || form->prec == -2) ? 0 : form->prec;
	front = s_space(form, len, sig, &space);
	if (form->mflag == 1 && !form->pnull)
		res = ft_strjoin_new4(sign, front, str, space);
	else if (form->mflag == 1 && form->pnull)
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
