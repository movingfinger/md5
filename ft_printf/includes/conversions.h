/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversions.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sako <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 15:31:39 by sako              #+#    #+#             */
/*   Updated: 2019/09/06 15:31:40 by sako             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONVERSIONS_H
# define CONVERSIONS_H

typedef char			*t_conversions(t_format *form, va_list args);
static t_conversions	*g_convert[] = {character, string, pointer, s_integer,\
	s_integer, octal, u_integer, hex_lower, hex_upper, ft_float, percent,\
	binary};

#endif
