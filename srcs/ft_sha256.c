/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sha256.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sako <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/30 22:37:11 by sako              #+#    #+#             */
/*   Updated: 2019/11/30 22:37:12 by sako             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

void	ft_sha256(char *str, t_md5 *md5)
{
	int		i;
	t_byte	hash[16];

	i = -1;
	ft_memset(hash, 0, 16);
	ft_memset(str, 0, 16);
//	md5_init(md5);
//	md5_pre_pad(md5, str);
//	md5_post_pad(md5, hash);
	while (++i < 4)
		ft_printf("%x\n", md5->state[i]);
	i = -1;
	while (++i < 16)
		ft_printf("%02x", hash[i]);
}
