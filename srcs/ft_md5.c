/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_md5.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sako <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 22:38:45 by sako              #+#    #+#             */
/*   Updated: 2019/11/23 22:04:53 by sako             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

int32_t	g_s[64] = {7, 12, 17, 22, 7, 12, 17, 22, 7, 12, 17, 22, 7, 12, 17, 22,
	5, 9, 14, 20, 5, 9, 14, 20, 5, 9, 14, 20, 5, 9, 14, 20,
	4, 11, 16, 23, 4, 11, 16, 23, 4, 11, 16, 23, 4, 11, 15, 23,
	6, 10, 15, 21, 6, 10, 15, 21, 6, 10, 15, 21, 6, 10, 15, 21};

int32_t g_k[64] = {0xd76aa478, 0xe8c7b756, 0x242070db, 0xc1bdceee,
	0xf57c0faf, 0x4787c62a, 0xa8304613, 0xfd469501,
	0x698098d8, 0x8b44f7af, 0xffff5bb1, 0x895cd7be,
	0x6b901122, 0xfd987193, 0xa679438e, 0x49b40821,
	0xf61e2562, 0xc040b340, 0x265e5a51, 0xe9b6c7aa,
	0xd62f105d, 0x02441453, 0xd8a1e681, 0xe7d3fbc8,
	0x21e1cde6, 0xc33707d6, 0xf4d50d87, 0x455a14ed,
	0xa9e3e905, 0xfcefa3f8, 0x676f02d9, 0x8d2a4c8a,
	0xfffa3942, 0x8771f681, 0x6d9d6122, 0xfde5380c,
	0xa4beea44, 0x4bdecfa9, 0xf6bb4b60, 0xbebfbc70,
	0x289b7ec6, 0xeaa127fa, 0xd4ef3085, 0x04881d05,
	0xd9d4d039, 0xe6db99e5, 0x1fa27cf8, 0xc4ac5665,
	0xf4292244, 0x432aff97, 0xab9423a7, 0xfc93a039,
	0x655b59c3, 0x8f0ccc92, 0xffeff47d, 0x85845dd1,
	0x6fa87e4f, 0xfe2ce6e0, 0xa3014314, 0x4e0811a1,
	0xf7537e82, 0xbd3af235, 0x2ad7d2bb, 0xeb86d391};

static BYTE pad[64] = {0x80, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0
};

BYTE **new_container(char *str, t_md5 *md5)
{
	BYTE 	**container;
	int		i;

	i = -1;
	container = (BYTE **)malloc(sizeof(BYTE*) * 2);
	container[0] = (BYTE *)malloc(sizeof(BYTE) * 64);
	container[1] = (BYTE *)malloc(sizeof(BYTE) * 64);
	ft_memset(container[0], 0, 64);
	ft_memset(container[1], 0, 64);
	return (container);
}

void	padding(t_md5 *md5, char *str)
{
	int		i;
	int		j;

	i = -1;
	j = -1;
	md5->bit_len = md5->length * 8;
	if (md5->alpha != 0)
	{
		while (++i < md5->length % 64)
			container[0][i] = (BYTE)str[64 * loop + i];
		container[0][++i] = 0x80;
		while (++j < 8)
			md5->container[0][56 + j] = md5->bit_len >> j * 8;
	}
	else if (md5->alpha == 0)
	{
		while (++i < 56)
			container[0][i] = (BYTE)str[64 * loop + i];
		container[0][++i] = 0x80;
		while (++j < 8)
			md5->container[1][56 + j] = md5->bit_len >> j * 8;
	}
	else
	{
		md5->bit_len = md5->length %
	}
}

int32_t *str2binary(char *str, t_md5 *md5)
{
	int		i;

	md5->length = ft_strlen(str);
	i = -1;
	md5->loop = md5->length / 64;
	md5->alpha = md5->length % 64 - 56;
	md5->num_448 = (md5->aplha >= 0) ? 64 - md5->alpha : -md5->alpha;
	while (++i < md5->length)
	{
		val = str[i];
	}
}1d5->loop

void	md5_init(t_md5 *md5)
{
	md5->length = 0;
	md5->bit_len = 0;
	md5->state[0] = 0x67452301;
	md5->state[1] = 0xefcdab89;
	md5->state[2] = 0x98badcfe;
	md5->state[3] = 0x10325476;
	md5->alpha = 
}

void	md5(void)
{
	t_md5 *md5;

	md5_init(md5);
}
