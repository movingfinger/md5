/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_charformat.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sako <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/30 22:06:41 by sako              #+#    #+#             */
/*   Updated: 2019/12/01 11:02:11 by sako             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*character(t_format *form, va_list args)
{
	int			len;
	char		*res;
	char		c;

	form->pnull = 0;
	res = NULL;
	if (form != NULL)
	{
		if (!(c = va_arg(args, int)))
			form->pnull = 1;
		else
		{
			res = (char *)malloc(sizeof(char) * 2);
			res[0] = c;
			res[1] = '\0';
		}
	}
	res = (res) ? res : ft_strdup("\0");
	len = ft_strlen(res);
	res = check_flag_width_char(form, len, res);
	return (res);
}

char	*string(t_format *form, va_list args)
{
	int		len;
	char	*res;
	char	*str;

	len = 0;
	res = NULL;
	if (form != NULL)
		res = va_arg(args, char *);
	str = (res) ? ft_strdup(res) : ft_strdup("(null)");
	res = check_flag_width_string(form, len, str);
	ft_strdel(&str);
	return (res);
}

char	*pointer(t_format *form, va_list args)
{
	char		*res;
	int			len;
	uintmax_t	temp;

	res = NULL;
	if (form != NULL)
	{
		temp = va_arg(args, uintmax_t);
		res = ft_itoa_base_unsigned(temp, 16);
		if (!ft_strcmp(res, "0") && (form->prec == -2 || form->prec == 0))
			res = ft_strdup("");
		ft_strtolower(res);
		len = ft_strlen(res);
		res = check_flag_width_pointer(form, len, res);
	}
	return (res);
}

char	*percent(t_format *form, va_list args)
{
	char		*res;

	(void)args;
	res = ft_strdup("%");
	res = check_flag_width_percent(form, res);
	return (res);
}
