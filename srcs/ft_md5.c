/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_md5.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sako <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 22:38:45 by sako              #+#    #+#             */
/*   Updated: 2019/11/25 19:40:46 by sako             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

void	md5_pre_pad(t_md5 *md5, char *data)
{
	int		i;
	size_t	len;

	i = -1;
	len = ft_strlen(data);
	while (++i < (int)len)
	{
		md5->data[md5->length] = data[i];
		md5->length++;
		if (md5->length == 64)
		{
			md5_process(md5, md5->data);
			md5->bit_len += 64;
			md5->length = 0;
		}
	}
}

void	md5_post_pad(t_md5 *md5, t_byte hash[])
{
	int	i;

	i = md5->length;
	if (md5->length < 56)
	{
		md5->data[i++] = 0x80;
		while (i < 56)
			md5->data[i++] = 0x00;
	}
	else if (md5->length >= 56)
	{
		md5->data[i++] = 0x80;
		while (i < 64)
			md5->data[i++] = 0x00;
		md5_process(md5, md5->data);
		ft_memset(md5->data, 0, 56);
	}
	md5->bit_len += md5->length * 8;
	i = 55;
	while (++i < 64)
		md5->data[i] = md5->bit_len >> (i - 56) * 8;
	md5_process(md5, md5->data);
	endian_word2byte(md5, hash);
}

void	md5_init(t_md5 *md5)
{
	md5->length = 0;
	md5->bit_len = 0;
	md5->state[0] = 0x67452301;
	md5->state[1] = 0xefcdab89;
	md5->state[2] = 0x98badcfe;
	md5->state[3] = 0x10325476;
	md5->temp[0] = md5->state[0];
	md5->temp[1] = md5->state[1];
	md5->temp[2] = md5->state[2];
	md5->temp[3] = md5->state[3];
	md5->var_f = 0;
	md5->var_g = 0;
	md5->endian = check_little_endian();
}

void	ft_md5(char *str, t_md5 *md5)
{
	int		i;
	t_byte	hash[16];

	i = -1;
	ft_memset(hash, 0, 16);
	md5_init(md5);
	md5_pre_pad(md5, str);
	md5_post_pad(md5, hash);
	i = -1;
	while (++i < 16)
		ft_printf("%02x", hash[i]);
}
