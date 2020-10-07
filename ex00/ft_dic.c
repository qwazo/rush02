/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dic.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paustin <paustin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/05 13:28:37 by paustin           #+#    #+#             */
/*   Updated: 2020/10/07 11:35:27 by paustin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_rush.h"

int		ft_dic_skipline(int fd)
{
	char	b;
	int		res;

	res = 0;
	b = 1;
	while (b != '\n')
	{
		res = read(fd, &b, 1);
		if (res <= 0)
			return (res);
		if (!(b == ' ' || b == ':' || ft_isp(b) || b == '\n' || ft_isdigit(b)))
			return (ST_EDIC);
	}
	return (2);
}

int		ft_dic_print(int fd, int dfl)
{
	char	b;
	int		res;
	char	bp;

	bp = 0;
	res = read(fd, &b, 1);
	while (b != '\n')
	{
		if (res <= 0)
			return (res);
		dfl = dfl + (b == ':');
		if (dfl > 1 || ft_isp(b) == 0)
			return (ST_EDIC);
		if (bp != ':' && bp != 0 && !(bp == ' ' && b == ' '))
			ft_putchar(bp);
		if ((bp == 0 && b != ' ' && b != ':') || bp != 0)
			bp = b;
		res = read(fd, &b, 1);
	}
	if (bp != ' ')
		ft_putchar(bp);
	return (ST_FND);
}

int		ft_dic_find(int fd, char *nbr)
{
	char	buff;
	int		res;

	while ((res = read(fd, &buff, 1)) > 0)
	{
		if (res <= 0)
			return (res);
		if (buff == '\n')
			return (ST_NLIN);
		if (*nbr != buff)
		{
			if (*nbr == 0 && ft_isdigit(buff) == 0)
			{
				if (buff == ' ' || buff == ':')
					return (buff == ':' ? ST_FND1 : ST_FND);
				else
					return (ST_EDIC);
			}
			else
				return (ST_NFND);
		}
		nbr++;
	}
	return (res);
}

int		ft_get_word(char *dic, char *nbr)
{
	int		fd;
	int		res;

	res = 2;
	if (dic == 0 || *dic == 0)
		res = -1;
	if ((fd = open(dic, O_RDONLY)) < 0)
		res = -1;
	while (res > 1 && res < 4)
	{
		res = ft_dic_find(fd, nbr);
		if (res == 2)
			res = ft_dic_skipline(fd);
	}
	if (res == 1 || res == 4)
		res = ft_dic_print(fd, (res == 4));
	if (res < 0 | close(fd) < 0)
	{
		ft_puterror("Dict Error\n");
		return (-1);
	}
	return (res);
}
