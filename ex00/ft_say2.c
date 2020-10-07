/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_say2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paustin <paustin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/04 23:09:22 by paustin           #+#    #+#             */
/*   Updated: 2020/10/07 10:14:59 by paustin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_rush.h"

int		ft_iszeroes(char *nbr)
{
	int zflag;

	zflag = 1;
	nbr++;
	while (*nbr != 0 && zflag == 1)
	{
		if (*nbr != '0')
			zflag = 0;
		nbr++;
	}
	return (zflag);
}

int		ft_countzeros(char *nbr)
{
	int i;

	i = 0;
	nbr++;
	while (*nbr != 0 && *nbr == '0')
	{
		i++;
		nbr++;
	}
	return (i);
}

int		ft_add_suffix(char *dic, char *nbr)
{
	int		res;
	char	*zs;
	int		z;

	z = 0;
	if (ft_tp(nbr) == 0 && ft_tn(nbr) > 0)
	{
		z = ft_countzeros(nbr);
		zs = ft_zeros(ft_tn(nbr) * 3 + 1);
		res = ft_checkdic(dic, zs, 1, (ft_strl(nbr) - 1 == z ? "" : TDELIM));
		free(zs);
		if (res < 0)
			return (res);
		if (res == 0)
			return (-2);
	}
	return (z);
}

int		ft_check_z(char *dic, char *nbr)
{
	int		i;
	char	*zs;
	int		res;

	i = 0;
	res = 0;
	while (i < ft_tn(nbr) * 3 && res == 0 && *nbr != '1')
	{
		zs = ft_endzero(nbr, i + 1);
		res = ft_checkdic(dic, zs, 1, DELIM);
		free(zs);
		if (res < 0)
			return (res);
		if (res > 0)
			return (ft_strl(nbr) - i - 1);
		if (i < 2)
			i++;
		else
			i = i + 3;
	}
	return (0);
}
