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
//		tmp = str;
		tmp = ft_strdup(str);
		str = ft_strjoin(str, c);
		free(tmp);
	}
//	ptr[0] = str;
	ptr[0] = ft_strdup(str);
}

int			bad_file(t_md5 *md5, char **av)
{
	if ((md5->fd = open(av[md5->pars], O_RDWR)) < 0)
	{
		if (ft_strcmp(av[1], "sha256") == 0)
			ft_printf("ft_ssl: sha256: ");
		if (ft_strcmp(av[1], "sha224") == 0)
			ft_printf("ft_ssl: sha224: ");
		else
			ft_printf("ft_ssl: md5: ");
		ft_putstr(av[md5->pars]);
		ft_printf(": No such file or directory\n");
		md5->pars++;
		return (-1);
	}
	return (0);
}

void		no_rotation(t_md5 *ssl, char **argv)
{
	if (!ssl->q)
	{
		if (ft_strcmp(argv[1], "sha256") == 0)
			ft_printf("SHA256 (\"");
		else
			ft_printf("MD5 (\"");
		ft_putstr(argv[ssl->pars]);
		ft_printf("\") = ");
	}
	if (ft_strcmp(argv[1], "sha256") == 0)
		ft_sha256(argv[ssl->pars], ssl);
	else
		ft_md5(argv[ssl->pars], ssl);
	ft_printf("\n");
}

void		rotate_s(t_md5 *ssl, char **argv)
{
	if (ft_strcmp(argv[1], "sha256") == 0)
		ft_sha256(argv[ssl->pars], ssl);
	else
	{
		ft_printf("MD5 (\"%s\") = ", argv[ssl->pars]);
		ft_md5(argv[ssl->pars], ssl);
	}
	if (!ssl->q)
		ft_printf(" \"%s\"\n", argv[ssl->pars]);
	else
		ft_printf("\n");
}

int			print_s(t_md5 *ssl, char **argv, int argc)
{
	if (ft_strcmp("-p", argv[ssl->pars]) == 0)
		ssl->p = 1;
	else if (ft_strcmp("-q", argv[ssl->pars]) == 0)
		ssl->q = 1;
	else if (ft_strcmp("-r", argv[ssl->pars]) == 0)
		ssl->r = 1;
	else if (ft_strcmp("-s", argv[ssl->pars]) == 0)
	{
		ssl->pars++;
		if (ssl->pars < argc)
		{
			if (!ssl->r)
				no_rotation(ssl, argv);
			else
				rotate_s(ssl, argv);
		}
	}
	else
		return (-1);
	ssl->pars++;
	return (0);
}
