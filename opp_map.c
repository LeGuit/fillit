/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opp_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndelmatt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/10 18:07:41 by ndelmatt          #+#    #+#             */
/*   Updated: 2015/12/10 18:08:13 by ndelmatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void			insert_piece(t_map *map, t_tetri *t)
{
	int         x;
	int         y;

	y = 0;
	while (y < t->height)
	{
		x = 0;
		while (x < t->width)
		{
			map->field[y + map->ycoord][x + map->xcoord] = t->piece[y][x];
		}
		x++;
	}
	y++;
}

void            remove_piece(t_map *map, t_tetri *t)
{
	int         x;
	int         y;

	y = 0;
	while (y < t->height)
	{
		x = 0;
		while (x < t->width)
		{
			map->field[y + map->ycoord][x + map->xcoord] = '.';
		}
		x++;
	}
	y++;
}
