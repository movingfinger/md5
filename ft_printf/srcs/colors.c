/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sako <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 22:30:05 by sako              #+#    #+#             */
/*   Updated: 2019/09/06 22:30:06 by sako             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_change_color(char *traverse, int *i)
{
	if (!ft_strncmp(traverse + *i, "{Red}", 5))
	{
		ft_putstr("\033[0;31m");
		*i += 5;
	}
	else if (!ft_strncmp(traverse + *i, "{Green}", 7))
	{
		ft_putstr("\033[0;32m");
		*i += 7;
	}
	else if (!ft_strncmp(traverse + *i, "{Blue}", 6))
	{
		ft_putstr("\033[0;34m");
		*i += 6;
	}
	else if (!ft_strncmp(traverse + *i, "{Finish}", 8))
	{
		ft_putstr("\033[0m");
		*i += 8;
	}
}

void	ft_print_letter(char *traverse, int *i, int *count)
{
	while (traverse[*i] && traverse[*i] != '%')
	{
		if (traverse[*i] == '{')
			ft_change_color(traverse, i);
		if (traverse[*i] && traverse[*i] != '%')
		{
			ft_putchar(traverse[(*i)++]);
			++*count;
		}
	}
}
