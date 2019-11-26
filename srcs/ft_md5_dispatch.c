/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_md5_dispatch.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sako <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 23:16:08 by sako              #+#    #+#             */
/*   Updated: 2019/11/25 23:16:10 by sako             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

void	calculate_f(t_md5 *md5, int i)
{
	md5->var_f = DEF_F(md5->temp[1], md5->temp[2], md5->temp[3]);
	md5->var_g = i;
}

void	calculate_g(t_md5 *md5, int i)
{
	md5->var_f = DEF_G(md5->temp[1], md5->temp[2], md5->temp[3]);
	md5->var_g = (5 * i + 1) % 16;
}

void	calculate_h(t_md5 *md5, int i)
{
	md5->var_f = DEF_H(md5->temp[1], md5->temp[2], md5->temp[3]);
	md5->var_g = (3 * i + 5) % 16;
}

void	calculate_i(t_md5 *md5, int i)
{
	md5->var_f = DEF_I(md5->temp[1], md5->temp[2], md5->temp[3]);
	md5->var_g = (7 * i) % 16;
}
