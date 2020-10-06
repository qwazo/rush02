/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_say_tri2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paustin <paustin@student.21-school>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/05 13:48:10 by paustin           #+#    #+#             */
/*   Updated: 2020/10/05 13:51:32 by paustin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_rush.h"

int		ft_tn(char *nbr)
{
	return ((ft_strl(nbr) - 1) / 3);
}

int		ft_tp(char *nbr)
{
	return ((ft_strl(nbr) - 1) % 3);
}

char	*ft_slice_tri(char *nbr)
{
	int		i;
	int		end;
	char	*tri;

	end = ft_tp(nbr) + 1;
	tri = malloc(end + 1);
	i = 0;
	while (i < end)
	{
		tri[i] = *nbr;
		i++;
		nbr++;
	}
	tri[i] = 0;
	return (tri);
}
