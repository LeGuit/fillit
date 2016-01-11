/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_valid.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndelmatt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/09 21:14:41 by ndelmatt          #+#    #+#             */
/*   Updated: 2016/01/11 17:22:35 by ndelmatt         ###   ########.fr       */
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

	i = 0;
	count = 0;
	while (i < 20)
	{
		if (buf[i] == '#')
			count++;
		i++;
	}
	if (count != 4)
		return (0);
	return (1);
}

static int		test_shape(char *buf)
{
	int			i;

	i = 0;
	while (i < 20)
	{
		if (buf[i] == '#')
		{
			if (!(buf[i - 1] == '#' || buf[i + 1] == '#'
					|| buf[i + 5] == '#' || buf[i - 5] == '#'))
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
			&& test_char(buf)
			&& test_duoh(buf)
			&& test_duov(buf))
		return (1);
	return (0);
}
