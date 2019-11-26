/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   endian.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sako <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 17:42:22 by sako              #+#    #+#             */
/*   Updated: 2019/11/25 15:38:48 by sako             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

int		to_big(int bits32)
{
	unsigned char	bytes[4];
	int				ret;

	bytes[0] = (unsigned char)((bits32 >> 0) & 0xff);
	bytes[1] = (unsigned char)((bits32 >> 8) & 0xff);
	bytes[2] = (unsigned char)((bits32 >> 16) & 0xff);
	bytes[3] = (unsigned char)((bits32 >> 24) & 0xff);
	ret = ((int)bytes[0] << 24) |
		((int)bytes[1] << 16) |
		((int)bytes[2] << 8) |
		((int)bytes[3] << 0);
	return (ret);
}

int		to_little(int bits32)
{
	unsigned char	bytes[4];
	int				ret;

	bytes[0] = (unsigned char)((bits32 >> 0) & 0xff);
	bytes[1] = (unsigned char)((bits32 >> 8) & 0xff);
	bytes[2] = (unsigned char)((bits32 >> 16) & 0xff);
	bytes[3] = (unsigned char)((bits32 >> 24) & 0xff);
	ret = ((int)bytes[0] << 0) |
		((int)bytes[1] << 8) |
		((int)bytes[2] << 16) |
		((int)bytes[3] << 24);
	return (ret);
}

/*
**	Check whether system is using little endian or big endian.
**	return 0 if it is big endian
**	return 1 if it is little endian
*/

int		check_little_endian(void)
{
	int		temp;
	char	*c;

	temp = 0x01234567;
	c = (char *)&temp;
	if (c[0] == 0x67)
		return (1);
	return (0);
}
