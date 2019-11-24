/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_new.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sako <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/25 14:53:44 by sako              #+#    #+#             */
/*   Updated: 2019/08/25 14:53:49 by sako             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin_new(char *s1, char *s2)
{
	char	*temp;

	temp = ft_strjoin(s1, s2);
	if (s1)
		ft_strdel(&s1);
	if (s2)
		ft_strdel(&s2);
	return (temp);
}

char	*ft_strjoin_new3(char *s1, char *s2, char *s3)
{
	char	*temp123;
	char	*temp23;

	temp23 = ft_strjoin(s2, s3);
	if (s2)
		ft_strdel(&s2);
	if (s3)
		ft_strdel(&s3);
	temp123 = ft_strjoin(s1, temp23);
	if (s1)
		ft_strdel(&s1);
	if (temp23)
		ft_strdel(&temp23);
	return (temp123);
}

char	*ft_strjoin_new4(char *s1, char *s2, char *s3, char *s4)
{
	char	*temp1234;
	char	*temp234;
	char	*temp34;

	temp34 = ft_strjoin(s3, s4);
	if (s3)
		ft_strdel(&s3);
	if (s4)
		ft_strdel(&s4);
	temp234 = ft_strjoin(s2, temp34);
	if (s2)
		ft_strdel(&s2);
	if (temp34)
		ft_strdel(&temp34);
	temp1234 = ft_strjoin(s1, temp234);
	if (s1)
		ft_strdel(&s1);
	if (temp234)
		ft_strdel(&temp234);
	return (temp1234);
}
