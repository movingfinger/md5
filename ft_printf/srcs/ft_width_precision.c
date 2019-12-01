/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_width_precision.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sako <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 22:26:00 by sako              #+#    #+#             */
/*   Updated: 2019/12/01 11:04:08 by sako             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		check_number_length(char *str)
{
	int		i;

	i = 0;
	while (ft_isdigit(str[i]))
		i++;
	return (i);
}

/*
**	check if printf parameter has width part, number or '*' which means readz
**	number from next argument. If width character is '*', width returns -1, and
**	index return 1. If width is number, width returnes number, and index returns
**	length of number. Other cases, width and index remains 0.
*/

int		ft_width_step(t_format *param, char *str, va_list args)
{
	int		index;

	index = 1;
	param->width = va_arg(args, int);
	if (str[1] && (ft_isdigit(str[1]) || str[1] == '.'))
	{
		str++;
		param->width = ft_atoi(str);
		index += check_number_length(str);
	}
	else
	{
		param->mflag = (param->width >= 0) ? 0 : 1;
		param->width = (param->width >= 0) ? param->width : -param->width;
	}
	return (index);
}

int		ft_checkwidth(char *str, t_format *param, va_list args)
{
	int		index;

	index = 0;
	if (str[0] == '*')
		index = ft_width_step(param, str, args);
	else if (ft_atoi(str) != 0)
	{
		param->width = ft_atoi(str);
		index = check_number_length(str);
	}
	else
	{
		param->wnull = 1;
		param->width = 0;
	}
	param->width = param->width;
	return (index);
}

/*
**	check if printf parameter has precision part, with '.' and number  and'*'
**	which means read number from next argument or nothing, means same as 0.
**	If width character is '.*', width returns -1, and index return 2. If
**	width is number, width returnes number, and index returns length of
**	number + 1. Other cases, width and index remains 0.
*/

int		ft_precision_step(char *temp, int *prec, va_list args)
{
	int		index;

	index = -1;
	if (temp[0] == '*')
	{
		index = 1;
		*prec = va_arg(args, int);
		if (*prec < 0)
			*prec = -1;
	}
	else if (ft_atoi(temp) == 0 && ft_isdigit(temp[0]))
	{
		index = check_number_length(temp);
		*prec = -2;
	}
	else if (!ft_isdigit(temp[0]))
	{
		index = 0;
		*prec = 0;
	}
	else if ((*prec = ft_atoi(temp)) != 0)
		index = check_number_length(temp);
	return (index);
}

int		ft_checkprecision(char *str, t_format *param, va_list args)
{
	int		prec;
	int		index;
	char	*temp;

	index = -1;
	prec = -1;
	if (str[0] == '.')
	{
		temp = ft_strsub(str, 1, ft_strlen(str) - 1);
		index = ft_precision_step(temp, &prec, args);
		if (temp)
			ft_strdel(&temp);
	}
	param->pnull = (!prec || prec == -1) ? 1 : 0;
	param->prec = prec;
	return (index + 1);
}
