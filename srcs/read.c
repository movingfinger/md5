/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sako <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/30 21:45:27 by sako              #+#    #+#             */
/*   Updated: 2019/11/30 21:45:29 by sako             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

void		fake_gnl(char **ptr, int fd)
{
	char	c[2];
	int		verif;
	char	*str;
	char	*tmp;

	c[1] = 0;
	verif = 42;
	str = ft_strdup("");
	while (verif > 0)
	{
		verif = read(fd, c, 1);
		if (verif == 0)
		{
			break ;
		}
		tmp = str;
		str = ft_strjoin(str, c);
		free(tmp);
	}
	ptr[0] = str;
}

int			bad_file(t_md5 *ssl, char **av)
{
	if ((ssl->fd = open(argv[ssl->pars], O_RDWR)) < 0)
	{
		if (ft_strcmp(argv[1], "sha256") == 0)
			ft_printf("ft_ssl: sha256: ");
		if (ft_strcmp(argv[1], "sha224") == 0)
			ft_printf("ft_ssl: sha224: ");
		else
			ft_printf("ft_ssl: md5: ");
		ft_putstr(argv[ssl->pars]);
		ft_printf(": No such file or directory\n");
		ssl->pars++;
		return (-1);
	}
	return (0);
}

static void		file_rotat(t_md5 *md5, char **av)
{
	if (bad_file(md5, argv) == -1)
		return ;
	fake_gnl(&md5->stdin, md5->fd);
	if (!md5->r)
		file_no_rotat(md5, av);
	else
	{
		ft_md5(md5->stdin, md5);
		else
			ft_printf("\n");
	}
	free(md5->stdin);
	close(md5->fd);
	ssl->pars++;
}