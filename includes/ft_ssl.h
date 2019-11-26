/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ssl.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sako <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 17:41:40 by sako              #+#    #+#             */
/*   Updated: 2019/11/25 16:50:27 by sako             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SSL_H
# define FT_SSL_H

# include "libft.h"

/*
**	macros
*/

# define ROT_LEFT(x,y) ((x << y) | (x >> (32 - y)))

# define DEF_F(x, y, z) ((x & y) | (~x & z))
# define DEF_G(x, y, z) ((x & z) | (y & ~z))
# define DEF_H(x, y, z) (x ^ y ^ z)
# define DEF_I(x, y, z) (y ^ (x | ~z))

/*
**	data type
*/

typedef unsigned char		t_byte;
typedef unsigned int		t_word;
typedef struct s_md5		t_md5;

struct						s_md5
{
	t_byte					data[64];
	t_word					length;
	unsigned long long int	bit_len;
	t_word					state[4];
	t_word					m[16];
	t_word					var_f;
	t_word					var_g;
	t_word					endian;
	t_word					temp[4];
};

/*
**	functions
*/

int							to_big(int bits3i2);
int							to_little(int bits32);
int							check_little_endian();
void						md5(char *str);
void						md5_process(t_md5 *md5, t_byte data[]);
void						calculate_f(t_md5 *md5, int i);
void						calculate_g(t_md5 *md5, int i);
void						calculate_h(t_md5 *md5, int i);
void						calculate_i(t_md5 *md5, int i);
void						endian_word2byte(t_md5 *md5, t_byte hash[]);
#endif
