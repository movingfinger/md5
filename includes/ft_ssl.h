/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ssl.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sako <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 17:41:40 by sako              #+#    #+#             */
/*   Updated: 2019/11/23 21:45:18 by sako             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SSL_H
# define FT_SSL_H

# include "libft.h"

/*
**	macros
*/

# define F(x, y, z) ((x & y) | (~x & z))
# define G(x, y, z) ((x & z) | (y & ~z))
# define H(x, y, z) (x ^ y ^ z)
# define I(x, y, z) (y ^ (x | ~z)):

/*
**	data type
*/

typedef unsigned char 		BYTE;
typedef unsigned int 		WORD;
typedef struct s_md5		t_md5;

struct						s_md5
{
	BYTE					message[64];
	WORD					length;
	unsigned long long int	bit_len;
	WORD					state[4];
	WORD					alpha;
	WORD					num448;
	WORD					loop;
	BYTE					**container;
};

/*
**	functions
*/

int							to_big(int bits3i2);
int							to_little(int bits32);
int							check_little_endian();
void						show_mem_rep(char *start, int n);

#endif
