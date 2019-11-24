/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isint.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sako <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/11 21:58:24 by sako              #+#    #+#             */
/*   Updated: 2019/08/11 21:59:15 by sako             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_isint(char *str)
{
	int		i;
	int		check_digit;

	i = -1;
	while (str[++i])
	{
		if (str[i] != '-')
		{
			check_digit = ft_isdigit((int)str[i]);
			if (!check_digit)
				return (0);
		}
	}
	return (1);
}
