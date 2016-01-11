/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_valid2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndelmatt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/11 15:44:57 by ndelmatt          #+#    #+#             */
/*   Updated: 2016/01/11 17:23:19 by ndelmatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int			test_duoh(char *buf)
{
	int		i;
	int		count;

	i = 5;
	count = 0;
	while (i < 14)
	{
		if (buf[i] == '#' && buf[i + 1] == '#')
		{
			count++;
			if (count == 2)
				break ;
			if (buf[i + 2] != '#' && buf[i - 1] != '#'
					&& buf[i + 5] != '#' && buf[i + 6] != '#'
					&& buf[i - 5] != '#' && buf[i - 4] != '#')
				return (0);
		}
		i++;
	}
	return (1);
}

int			test_duov(char *buf)
{
	int		i;
	int		count;

	i = 5;
	count = 0;
	while (i < 14)
	{
		if (buf[i] == '#' && buf[i + 5] == '#')
		{
			count++;
			if (count == 2)
				break ;
			if (buf[i + 4] != '#' && buf[i + 6] != '#'
					&& buf[i + 10] != '#' && buf[i - 5] != '#'
					&& buf[i - 1] != '#' && buf[i + 1] != '#')
				return (0);
		}
		i++;
	}
	return (1);
}
