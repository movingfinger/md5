/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sako <sako@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/11 10:23:39 by sako              #+#    #+#             */
/*   Updated: 2019/12/01 10:44:05 by sako             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

/*
** library headers
*/

# include <stdarg.h>
# include <stdlib.h>
# include <limits.h>

/*
**	define
*/

/*
**	structure
*/

typedef struct	s_format
{
	char		*flag;
	char		*length;
	int			prec;
	char		type;
	int			width;
	int			mflag;
	int			fnull;
	int			pnull;
	int			wnull;
}				t_format;

/*
** functions
*/

char			*character(t_format *form, va_list args);
char			*string(t_format *form, va_list args);
char			*pointer(t_format *form, va_list args);
char			*s_integer(t_format *form, va_list args);
char			*u_integer(t_format *form, va_list args);

/*
**	ft_printfuncs.c
*/

int				ft_printfunc_char(int count);
int				ft_printfunc(t_format form, va_list args);

/*
**	ft_printf.c
*/

char			*ft_format(t_format *form, va_list args);
int				ft_traverse_step(t_format *form, va_list args,\
				char *param, int *count);
int				ft_storeformat(char *traverse, t_format *form, va_list args);
int				ft_parse(va_list arg, const char *format);
int				ft_printf(const char *format, ...);

/*
**	ft_parameters.c
*/

int				ft_checkflag(char *str, t_format *param);
int				ft_checklength(char *str, t_format *param);
int				ft_checktype(char *str, t_format *param);

/*
**	ft_width_precision.c
*/

int				ft_checkwidth(char *str, t_format *param, va_list args);
int				ft_checkprecision(char *str, t_format *param, va_list args);

/*
**	ft_binaryformat.c
*/

char			*binary(t_format *form, va_list args);

/*
**	ft_charformat.c
*/

char			*character(t_format *form, va_list args);
char			*string(t_format *form, va_list args);
char			*pointer(t_format *form, va_list args);
char			*percent(t_format *form, va_list args);

/*
**	ft_intformat.c
*/

char			*u_integer(t_format *form, va_list args);
char			*s_integer(t_format *form, va_list args);
char			*octal(t_format *form, va_list args);
char			*hex_lower(t_format *form, va_list args);
char			*hex_upper(t_format *form, va_list args);

/*
**   ft_flaot_format.c
*/
char			*ft_float(t_format *form, va_list args);

/*
**	ft_check_flags.c
*/

char			*check_flag_width_octal(t_format *form, int len, char *str);
char			*check_flag_width_pointer(t_format *form, int len, char *str);

/*
**	ft_check_flags_int.c
*/

char			*check_flag_width_unsigned(t_format *form, char *str);
char			*check_flag_width_signed(t_format *form, int len, char *str);

/*
**	ft_check_flag_char.c
*/

char			*check_flag_width_char(t_format *form, int len, char *str);
char			*check_flag_width_string(t_format *form, int len, char *str);
char			*check_flag_width_percent(t_format *form, char *str);

/*
**	ft_check_flag_hex.c
*/

char			*check_flag_width_hex(t_format *form, char *hex, char *str);

/*
**	ft_check_flag_float.c
*/

char			*check_flag_width_float(t_format *form, int len, int width,\
				char *str);

/*
**	ft_convert.c
*/

uintmax_t		convert2u_int(t_format *form, va_list args);
intmax_t		convert2s_int(t_format *form, va_list args);
long double		convert2float(t_format *form, va_list args);

/*
**	colors.c
*/

void			ft_print_letter(char *traverse, int *i, int *count);
#endif
