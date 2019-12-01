/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sako <sako@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/13 22:29:24 by sako              #+#    #+#             */
/*   Updated: 2019/07/29 04:01:03 by sako             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "conversions.h"

char	*ft_format(t_format *form, va_list args)
{
	size_t		i;
	char		*final;
	char		*conv;

	i = -1;
	conv = ft_strdup("cspdiouxXf%b");
	final = NULL;
	while (++i < ft_strlen(conv))
	{
		if (conv[i] == form->type)
			final = g_convert[i](form, args);
	}
	ft_strdel(&conv);
	return (final);
}

int		ft_traverse_step(t_format *form, va_list args, char *param, int *count)
{
	int		index;
	int		idx;

	index = ft_checkflag(param, form);
	idx = index;
	param = ft_strsub_new(param, index, ft_strlen(param) - index);
	idx += (index = ft_checkwidth(param, form, args));
	param = ft_strsub_new(param, index, ft_strlen(param) - index);
	idx += (index = ft_checkprecision(param, form, args));
	param = ft_strsub_new(param, index, ft_strlen(param) - index);
	idx += (index = ft_checklength(param, form));
	param = ft_strsub_new(param, index, ft_strlen(param) - index);
	idx += ft_checktype(param, form);
	if (param)
		ft_strdel(&param);
	*count += ft_printfunc(*form, args);
	return (idx);
}

int		ft_storeformat(char *traverse, t_format *form, va_list args)
{
	char		*param;
	int			count;
	int			idx;
	int			i;

	i = 0;
	count = 0;
	while (traverse[i])
	{
		ft_print_letter(traverse, &i, &count);
		if (traverse[i])
		{
			param = ft_strsub(traverse, i + 1, ft_strlen(traverse) - i - 1);
			i += (idx = ft_traverse_step(form, args, param, &count)) ? idx : 0;
		}
		else
			break ;
		i++;
	}
	return (count);
}

int		ft_parse(va_list args, const char *format)
{
	t_format	form;
	int			count;

	count = ft_storeformat((char *)format, &form, args);
	va_end(args);
	if (form.flag)
		ft_strdel(&form.flag);
	if (form.length)
		ft_strdel(&form.length);
	return (count);
}

int		ft_printf(const char *format, ...)
{
	va_list	args;
	int		count;

	va_start(args, format);
	count = ft_parse(args, format);
	return (count);
}
