/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_flag_hex.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sako <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/11 14:49:45 by sako              #+#    #+#             */
/*   Updated: 2019/12/01 11:12:28 by sako             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*get_front(t_format *form, char *hex, char **str, int *len)
{
	char	*front;
	int		size;

	*len = ft_strlen(*str) + ((hex) ? ft_strlen(hex) : 0);
	if (!ft_strcmp(*str, "0") && (!form->prec || form->prec == -2))
	{
		*str = ft_strdup("");
		*len = 0;
	}
	form->prec = (form->pnull || form->prec == -2) ? 0 : form->prec;
	size = form->prec - *len + (((hex[0] != '\0') && form->wnull) ? 2 : 0);
	front = ft_memalloc_specific('0', (form->prec) ? size : 0);
	if (!front)
		front = ft_memalloc_specific('\0', 1);
	return (front);
}

char	*check_flag_width_hex(t_format *form, char *hex, char *str)
{
	int			len;
	char		*res;
	char		*front;
	char		*space;

	front = get_front(form, hex, &str, &len);
	if (!(space = ft_memalloc_specific((ft_strchr(form->flag, '0') &&\
	(form->pnull && form->mflag == 0) ? '0' : ' '), form->width\
	- (((form->prec && form->prec >= len) ? form->prec : len)))))
		space = ft_memalloc_specific('\0', 1);
	if (form->mflag == 1 && !form->pnull)
		res = ft_strjoin_new4(hex, front, str, space);
	else if (form->mflag == 1 && form->pnull)
		res = ft_strjoin_new4(front, hex, str, space);
	else if (form->pnull && ft_strchr(form->flag, '0'))
		res = ft_strjoin_new4(front, hex, space, str);
	else if (form->pnull)
		res = ft_strjoin_new4(front, space, hex, str);
	else if (form->width < form->prec)
		res = ft_strjoin_new4(hex, front, str, space);
	else
		res = ft_strjoin_new4(space, hex, front, str);
	return (res);
}
