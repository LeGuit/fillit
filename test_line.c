/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwoodwar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/03 15:00:15 by gwoodwar          #+#    #+#             */
/*   Updated: 2015/12/03 20:11:05 by gwoodwar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
/*
static int		test_input(char *buf)
{
	int			i;

	i = 0;
	while (i < 21)
	{
		if ((i % 5 == 4 && buf[i] != '\n')
				|| (i % 5 != 4 && (buf[i] != '#' || buf[i] != '.')))
			return (0);
		i++;
	}
	if (buf[i] != '\n')
		return (0);
	return (1);
}
*/

static int		test_4tetri(char *buf)
{
	int			i;
	int			count;

	ft_putendl("test 4tetri : ");
	i = 0;
	count = 0;
	while (i < 21)
	{
		if (buf[i] == '#')
			count++;
		i++;
	}
	if (count > 4)
		return (0);
	return (1);
}

static int		test_shape(char *buf)
{
	int			i;

	i = 0;
	while (i < 16)
	{
		if (buf[i] == '#'
			&& buf[i + 1] == '#' && buf[i + 5] == '#')
		return (0);
//		ft_putstr("count : ");
//		ft_putnbr(count);
//		ft_putchar('\n');
//		ft_putstr("buf : ");
//		ft_putchar(buf[i]);
//		ft_putchar('\n');
//		ft_putstr("buf + 1 : ");
//		ft_putchar(buf[i + 1]);
//		ft_putchar('\n');
//		ft_putstr("buf + 5 : ");
//		ft_putchar(buf[i + 5]);
//		ft_putchar('\n');
		i++;
	}
	return (0);
}

int				is_valid(char *buf)
{
	if (test_4tetri(buf)
		  && /*test_input(buf)
		  &&*/ test_shape(buf))
		return (1);
	return (0);
}
