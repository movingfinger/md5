/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sako <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 23:21:59 by sako              #+#    #+#             */
/*   Updated: 2019/11/25 16:25:17 by sako             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

static void		file_no_rotat(t_md5 *md5, char **av)
{
	if (!md5->q)
	{
		if (ft_strcmp(av[1], "sha256") == 0)
			ft_printf("SHA256 (");
		else
			ft_printf("MD5 (");
		ft_printf("%s) = ", av[md5->pars]);
	}
	if (ft_strcmp(av[1], "sha256") == 0)
		ft_sha256(md5->stdin, md5);
	else
		ft_md5(md5->stdin, md5);
	ft_putstr("\n");
}

static void		file_rotat(t_md5 *md5, char **av)
{
	if (bad_file(md5, av) == -1)
		return ;
	fake_gnl(&md5->stdin, md5->fd);
	if (!md5->r)
		file_no_rotat(md5, av);
	else
	{
		if (ft_strcmp(av[1], "sha256") == 0)
			ft_sha256(md5->stdin, md5);
		else
			ft_md5(md5->stdin, md5);
		if (!md5->q)
			ft_printf(" %s\n", av[md5->pars]);
		else
			ft_printf("\n");
	}
	free(md5->stdin);
	close(md5->fd);
	md5->pars++;
}

static void		flags(t_md5 *md5, int ac, char **av)
{
	md5->i = 2;
	md5->p = 0;
	md5->q = 0;
	md5->r = 0;
	md5->s = 0;
	while (md5->i < ac)
	{
		if (ft_strcmp("-p", av[md5->i]) == 0)
			md5->p = 1;
		else if (ft_strcmp("-q", av[md5->i]) == 0)
			md5->q = 1;
		else if (ft_strcmp("-r", av[md5->i]) == 0)
			md5->r = 1;
		else if (ft_strcmp("-s", av[md5->i]) == 0)
		{
			md5->i++;
			md5->s++;
		}
		else
			break ;
		md5->i++;
	}
	md5->n_file = md5->i - ac;
}

static void		md5_sha_dec(t_md5 *ssl, char **av, int ac)
{
	flags(ssl, ac, av);
	if (ssl->p || (!ssl->n_file && !ssl->s))
	{
		fake_gnl(&ssl->stdin, 0);
		ft_printf("hear?\n");
		if (ssl->p)
			ft_printf("%s", ssl->stdin);
		if (ft_strcmp(av[1], "sha256") == 0)
			ft_sha256(ssl->stdin, ssl);
		else
			ft_md5(ssl->stdin, ssl);
		ft_printf("\n");
		free(ssl->stdin);
	}
	ssl->pars = 2;
	while (ssl->pars < ac)
		if (print_s(ssl, av, ac) == -1)
			break ;
	while (ssl->pars < ac)
		file_rotat(ssl, av);
}

int				main(int ac, char **av)
{
	t_md5	ssl;

	if (ac == 1)
	{
		ft_printf("usage: ft_ssl command [command opts] [command args]\n");
		exit(-1);
	}
	if (ft_strcmp(av[1], "md5") == 0 || ft_strcmp(av[1], "sha256") == 0)
		md5_sha_dec(&ssl, av, ac);
	else
	{
		ft_printf("ft_ssl: Error: '%s' is an invalid command.\n\nStandard \
commands:\n\nMessage Digest commands:\nmd5\nsha256\n\nCipher \
commands:\n", av[1]);
		exit(-1);
	}
	return (0);
}