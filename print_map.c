/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndelmatt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/10 17:37:37 by ndelmatt          #+#    #+#             */
/*   Updated: 2016/01/18 20:01:04 by ngoguey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void			print_map(t_map *map)
{
	int	x;
	int y;

	y = 0;
	while (y < map->minsquare)
	{
		x = 0;
		while (x < map->minsquare)
		{
			ft_putchar(map->field[y][x]);
			x++;
		}
		y++;
		ft_putchar('\n');
	}
}
