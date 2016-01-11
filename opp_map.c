/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opp_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndelmatt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/10 18:07:41 by ndelmatt          #+#    #+#             */
/*   Updated: 2016/01/11 17:24:34 by ndelmatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void			insert_piece(t_map *map, t_tetri *t)
{
	int			x;
	int			y;

	t->mempos[0] = map->ycoord;
	t->mempos[1] = map->xcoord;
	y = 0;
	while (y < t->height)
	{
		x = 0;
		while (x < t->width)
		{
			if (ft_isalpha(t->piece[y][x]))
				map->field[y + map->ycoord][x + map->xcoord] = t->piece[y][x];
			x++;
		}
		y++;
	}
	map->xcoord = 0;
	map->ycoord = 0;
}

void			remove_piece(t_map *map, t_tetri *t)
{
	int			x;
	int			y;

	y = 0;
	while (y < t->height)
	{
		x = 0;
		while (x < t->width)
		{
			if (ft_isalpha(t->piece[y][x]))
				map->field[y + t->mempos[0]][x + t->mempos[1]] = '.';
			x++;
		}
		y++;
	}
	map->xcoord = t->mempos[1];
	map->ycoord = t->mempos[0];
}
