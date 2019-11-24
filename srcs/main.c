/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sako <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 23:21:59 by sako              #+#    #+#             */
/*   Updated: 2019/11/22 13:35:27 by sako             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"
#include <stdio.h>
#include <stdlib.h>

int		main(int ac, char **av)
{
	if (ac < 2)
		ft_putendl("usage: ft_ssl command [command opts] [command args]");
	else
	{
		ft_putendl(av[1]);
		printf("%s\n", check_little_endian() == 0 ? "Big endian" : "Little endian");
	}
	return (0);
}
