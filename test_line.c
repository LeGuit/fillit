/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwoodwar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/03 15:00:15 by gwoodwar          #+#    #+#             */
/*   Updated: 2015/12/04 11:45:50 by gwoodwar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int		test_endl(char *buf)
{
	int			i;

	i = 0;
	while (i < 20)
	{
		if (i % 5 == 4 && buf[i] != '\n')
			return (0);
		i++;
	}
	if (ft_strlen(buf) == 21 && buf[i] != '\n')
		return (0);
	return (1);
}

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

	i = 5;
	while (i < 16)
	{
		if (buf[i] == '#')
		{
			if (buf[i - 1] != '#' && buf[i + 1] != '#'
					&& buf[i + 5] != '#' && buf[i - 5] != '#')
				return (0);
		}
		i++;
	}
	return (1);
}

static int		test_char(char *buf)
{
	int			i;

	i = 0;
	while (i < 19)
	{
		if (i % 5 != 4 && buf[i] != '#' && buf[i] != '.')
			return (0);
		i++;
	}
	return (1);

}

int				is_valid(char *buf)
{
	if (test_4tetri(buf)
			&& test_endl(buf)
			&& test_shape(buf)
			&& test_char(buf))
		return (1);
	return (0);
}
