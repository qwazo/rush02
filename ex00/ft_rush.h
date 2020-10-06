/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rush.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paustin <paustin@student.21-school>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/05 13:35:37 by paustin           #+#    #+#             */
/*   Updated: 2020/10/05 13:37:45 by paustin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_RUSH_H
# define FT_RUSH_H

# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <stdio.h>

# define DICNAME "numbers.dict"
# define TDELIM ", "
# define HDELIM " and "
# define DDELIM "-"
# define DELIM " "

# define ST_EDIC -2
# define ST_ERR -1
# define ST_EOF 0
# define ST_FND 1
# define ST_NFND 2
# define ST_NLIN 3
# define ST_FND1 4
# define BUFFSIZE 1000

int		ft_isdigit(char c);
int		ft_isspace(char c);
int		ft_isnumber(char *str);
int		ft_isp(char c);

int		ft_get_word(char *dic, char *nbr);

void	ft_putchar(char c);
void	ft_putstr(char *str);
void	ft_puterror(char *err);
int		ft_strl(char *str);

char	*ft_endzero(char *str, int nb);
char	*ft_zeros(int len);
char	*ft_getdigit(char c);

int		ft_tn(char *nbr);
int		ft_tp(char *nbr);
char	*ft_slice_tri(char *nbr);
int		ft_say_tri(char *dic, char *nbr, int last);

int		ft_checkdic(char *dic, char *nbr, int sflag, char *spc);
int		ft_say_input(char *dic);
int		ft_say_arg(char *dic, char *nmb);

int		ft_iszeroes(char *nbr);
int		ft_countzeros(char *nbr);
int		ft_add_suffix(char *dic, char *nbr);
int		ft_check_z(char *dic, char *nbr);

#endif
