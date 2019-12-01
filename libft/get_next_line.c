/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sako <sako@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/15 23:10:34 by sako              #+#    #+#             */
/*   Updated: 2019/10/04 20:05:22 by sako             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*strjoin_free(char **s1, const char *s2)
{
	char	*temp;

	temp = ft_strjoin(*s1, s2);
	free(*s1);
	return (temp);
}

char	*strdup_from_len(char **s, int len)
{
	char	*temp;

	temp = ft_strdup(*s + len + 1);
	free(*s);
	return (temp);
}

int		store_one_line(char **str, char **line, int fd, int re)
{
	int		len;

	len = 0;
	while (str[fd][len] != '\n' && str[fd][len] != '\0')
		len++;
	if (str[fd][len] == '\n')
	{
		*line = ft_strsub(str[fd], 0, len);
		str[fd] = strdup_from_len(&str[fd], len);
		if (str[fd][0] == '\0')
			ft_strdel(&str[fd]);
	}
	else if (str[fd][len] == '\0')
	{
		if (re == BUFF_SIZE)
			return (get_next_line(fd, line));
		*line = ft_strdup(str[fd]);
		ft_strdel(&str[fd]);
	}
	return (1);
}

int		return_line(const int fd, char **line, char **str, int re)
{
	if (re < 0)
		return (-1);
	else if (re == 0 && (!str[fd] || str[fd][0] == '\0'))
		return (0);
	return (store_one_line(str, line, fd, re));
}

int		get_next_line(const int fd, char **line)
{
	static char	*str[FD_SIZE];
	char		buf[BUFF_SIZE + 1];
	int			re;

	if (fd < 0 || !line)
		return (-1);
	while ((re = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[re] = '\0';
		if (!str[fd])
			str[fd] = ft_strnew(1);
		str[fd] = strjoin_free(&(str[fd]), buf);
		if (ft_strchr(buf, '\n'))
			break ;
	}
	return (return_line(fd, line, str, re));
}
