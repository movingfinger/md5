/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printfuncs.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sako <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/03 22:40:53 by sako              #+#    #+#             */
/*   Updated: 2019/09/03 22:41:22 by sako             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_printfunc_char(int count)
{
	int		i;

	i = count - 1;
	write(1, "\0", 1);
	while (i--)
		write(1, " ", 1);
	return (count);
}

int		ft_printfunc(t_format form, va_list args)
{
	char	*final;
	int		count;

	final = ft_format(&form, args);
	if (form.type == 'c')
	{
		count = ft_strlen(final) + ((form.pnull) ? 1 : 0);
		if (form.width > 0 && form.mflag == 1 && form.pnull)
			return (ft_printfunc_char(count));
	}
	else
	{
		if (!final && !form.pnull)
			count = 0;
		else
			count = (final) ? ft_strlen(final) : 1;
	}
	if (!form.type)
		count = 0;
	write(1, final, count);
	if (final)
		ft_strdel(&final);
	return (count);
}
