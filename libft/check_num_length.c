/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_num_length.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sako <sako@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/05 22:47:39 by sako              #+#    #+#             */
/*   Updated: 2019/07/29 03:20:57 by sako             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		check_unsigned_num_len(uintmax_t n)
{
	int		length;

	length = 0;
	if (n == 0)
		return (1);
	while (n > 0)
	{
		n /= 10;
		length++;
	}
	return (length);
}

int		check_signed_num_len(long long int n)
{
	int		length;

	length = 0;
	if (n == 0)
		return (1);
	if (n < 0)
		++length;
	while (n != 0)
	{
		n /= 10;
		++length;
	}
	return (length);
}
