/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paustin <paustin@student.21-school>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/03 12:03:34 by paustin           #+#    #+#             */
/*   Updated: 2020/10/05 13:53:44 by paustin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_rush.h"

int		main(int argc, char **argv)
{
	char	*dic;
	int		i;

	dic = DICNAME;
	if (argc > 2)
		dic = argv[1];
	if (argc == 1)
		ft_say_input(dic);
	if (argc == 2)
	{
		ft_say_arg(dic, argv[1]);
	}
	if (argc > 2)
	{
		i = 2;
		while (i < argc)
		{
			ft_say_arg(dic, argv[i]);
			i++;
		}
	}
	return (0);
}
