/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwoodwar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/03 12:27:37 by gwoodwar          #+#    #+#             */
/*   Updated: 2015/12/03 12:52:02 by gwoodwar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int		test_input(char *line)
{
	int		i;

	i = 0
	while (line[i])
	{
		if (((i % 5 != 4 && i % 21 != 0) 
				&& (line[i] != '#' || line[i] != '.'))
				|| ((i % 21 == 0) && line[i] != '\n'))
			return (0);
		i++;
	}
	return (1);
}

static int		test_endl(char *line)
{
	int		i;

	i = 21;
	while (line[i])
	{
		if (line[i] != '\n')
			return (0);
		i += 21;
	}
	return (1);
}

static int		test_4tetri(char *line)
{
	size_t		i;

	i = ft_strlen(line) / 21;
	while (*line && i != 0)
	{
		if (*line == '#')
			i--;
		line++;
	}
	if (*line)
		return (0);
	return (1);
}

int		is_valid(char *line)
{
	if (test_4tetri(line) && test_endl(line) && test_input(line))
		return (1);
	return (0);
}
