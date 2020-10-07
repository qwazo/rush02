/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paustin <paustin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/03 12:03:34 by paustin           #+#    #+#             */
/*   Updated: 2020/10/07 10:17:19 by paustin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_rush.h"

int		main(int argc, char **argv)
{
	char	*dic;
	int		i;
	int		res;

	dic = DICNAME;
	if (argc > 2)
		dic = argv[1];
	if (argc == 1)
		ft_say_input(dic);
	if (argc == 2)
	{
		res = ft_say_arg(dic, argv[1]);
	}
	if (argc > 2)
	{
		i = 2;
		while (i < argc)
		{
			res = ft_say_arg(dic, argv[i]);
			i++;
			if (res == -2)
				return (res);
		}
	}
	return (res);
}
