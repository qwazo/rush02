/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_io.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paustin <paustin@student.21-school>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/28 19:12:13 by paustin           #+#    #+#             */
/*   Updated: 2020/10/05 13:09:01 by paustin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_rush.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	while (*str != 0)
		write(1, str++, 1);
}

void	ft_puterror(char *err)
{
	while (*err != 0)
		write(2, err++, 1);
}

int		ft_strl(char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}
