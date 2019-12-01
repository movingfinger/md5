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
# include "ft_printf.h"

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
	char					*stdin;
	int						fd;
	int						pars;
	int 					i;
	int 					n_file;
	t_word					p;
	t_word					q;
	t_word					r;
	t_word					s;
};

/*
**	functions
*/

int							to_big(int bits3i2);
int							to_little(int bits32);
int							check_little_endian();
void						ft_md5(char *str, t_md5 *md5);
void						ft_sha256(char *str, t_md5 *md5);
void						md5_process(t_md5 *md5, t_byte data[]);
void						calculate_f(t_md5 *md5, int i);
void						calculate_g(t_md5 *md5, int i);
void						calculate_h(t_md5 *md5, int i);
void						calculate_i(t_md5 *md5, int i);
void						endian_word2byte(t_md5 *md5, t_byte hash[]);
int							bad_file(t_md5 *md5, char **av);
void						fake_gnl(char **ptr, int fd);
int							print_s(t_md5 *ssl, char **argv, int argc);

#endif
