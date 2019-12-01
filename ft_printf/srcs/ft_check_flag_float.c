/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_flag_float.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sako <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/03 23:04:16 by sako              #+#    #+#             */
/*   Updated: 2019/12/01 11:03:43 by sako             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*check_flag_width_float(t_format *form, int len, int width, char *str)
{
	char		sign;
	char		*space;

	sign = (str[0] == '-') ? '-' : '+';
	if (ft_strchr(form->flag, '+') && (sign == '+'))
		str = ft_strjoin_free_end("+", str);
	if (ft_strchr(form->flag, ' ') && (sign == '+'))
		str = ft_strjoin_free_end(" ", str);
	len = ft_strlen(str);
	if (width > 0 && (len < width))
	{
		space = ft_memalloc_specific(' ', width - len);
		if (form->fnull && ft_strchr(form->flag, '0'))
		{
			space = ft_memset(space, '0', width - len);
			if (form->flag[0] != '0')
			{
				space[0] = (sign == '-') ? '-' : form->flag[0];
				str[0] = '0';
			}
		}
		str = (form->mflag == 1) ? ft_strjoin_new(str, space)\
		: ft_strjoin_new(space, str);
	}
	return (str);
}
