/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parameters.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sako <sako@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/24 23:13:50 by sako              #+#    #+#             */
/*   Updated: 2019/07/29 03:51:59 by sako             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
**	check if printf parameter has flag parts, {'-', '+', '#', '0', ' '},
** continuously, and return the flag character arrays if possible. No flag
** characters exist, return NULL.
*/

int		ft_str_search_index(char *str, char *flags)
{
	int		i;
	int		j;
	int		find;
	int		index;

	i = -1;
	index = -1;
	while (str[++i] && find)
	{
		j = -1;
		find = 0;
		while (flags[++j])
		{
			if (str[i] == flags[j])
			{
				index = (index > i) ? index : i;
				find = 1;
			}
		}
	}
	return (index);
}

int		ft_checkflag(char *str, t_format *param)
{
	char	*flags;
	int		index;

	flags = ft_strdup("-+#0 ");
	index = ft_str_search_index(str, flags);
	param->fnull = (index == -1) ? 1 : 0;
	if (index == -1)
		param->flag = NULL;
	else
		param->flag = ft_strsub(str, 0, index + 1);
	param->mflag = ft_strchr(param->flag, '-') ? 1 : 0;
	free(flags);
	return (index + 1);
}

/*
**	check printf parameter has length characters, {hh, h, l, ll, L, j}.
**	'j' is bonus part for "d, i for intmax_t, and o, u, x, X for uintmax_t"
*/

int		ft_checklength(char *str, t_format *param)
{
	int		index;

	index = 0;
	param->length = NULL;
	if (str[0] == 'h' && !ft_strnstr(str, "hh", 2))
		param->length = ft_strdup("h");
	else if (str[0] == 'l' && !ft_strnstr(str, "ll", 2))
		param->length = ft_strdup("l");
	else if (ft_strnstr(str, "L", 1))
		param->length = ft_strdup("L");
	else if (ft_strnstr(str, "hh", 2))
		param->length = ft_strdup("hh");
	else if (ft_strnstr(str, "ll", 2))
		param->length = ft_strdup("ll");
	else if (ft_strnstr(str, "j", 1))
		param->length = ft_strdup("j");
	else if (ft_strnstr(str, "z", 1))
		param->length = ft_strdup("z");
	if (param->length)
		index = ft_strlen(param->length);
	return (index);
}

/*
**	check which type parameter is.
**	c (char), s(string), p(ptr)
**	d, i(int), o(oct), u(unsigned int), xX (hex),
**	return 0 if t_format param is empty, and return 1 if any types are found.
*/

int		ft_checktype(char *str, t_format *param)
{
	char	*types;
	int		i;

	i = -1;
	param->type = 0;
	types = ft_strdup("diuoxXfFeEgGaAcspnb%");
	while (types[++i])
	{
		if (str && str[0] == types[i])
			param->type = types[i];
	}
	ft_strdel(&types);
	if (!param->type)
		return (0);
	return (1);
}
