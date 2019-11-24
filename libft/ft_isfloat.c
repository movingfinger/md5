/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isfloat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sako <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/11 21:57:48 by sako              #+#    #+#             */
/*   Updated: 2019/08/11 21:58:51 by sako             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_isfloat(char *str)
{
	int		i;
	int		check_digit;
	int		check_dot;
	int		check_minus;

	i = -1;
	while (str[++i])
	{
		check_digit = ft_isdigit((int)str[i]);
		check_dot = str[i] == '.';
		check_minus = str[i] == '-';
		if (!check_digit && !check_dot && !check_minus)
			return (0);
	}
	return (1);
}
