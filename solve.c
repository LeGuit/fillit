/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwoodwar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/04 16:08:24 by gwoodwar          #+#    #+#             */
/*   Updated: 2015/12/11 14:54:54 by gwoodwar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static void		gen_map(t_map *map)
{
	int			x;
	int			y;

	y = 0;
	while (y < MAP_SIZE)
	{
		x = 0;
		while (x < MAP_SIZE)
		{
			map->field[y][x] = '.';
			x++;
		}
		y++;
	}
	map->minsquare = 2;
	map->xcoord = 0;
	map->ycoord = 0;
}

void			start_solve(t_list **lst)
{
	t_map		*map;

	gen_map(map);
	recursive_start(map, *lst);
	print_map(map);
}

void			recursive_start(t_map *map, t_list **head)
{
	while (map->ycoord < map->minsquare)
	{
		while (map->xcoord < map->minsquare)
		{
			if (map->field[x][y] == '.')
			{
				if (!test_piece(map, *head))
				{
					map->minsquare += 1;
					solve(map, head);
				}
			}
			map->xcoord++;
		}
		map->ycoord++;
	}
}

int				test_piece(t_map *map, t_tetri *t)
{
	int			x;
	int			y;

	if (map->ycoord == map->minsquare)
		return (0);
	y = 0;
	while (y < t->height)
	{
		if (map->minsquare - map->xcoord < t->width)
		{
			map->ycoord++;
			test_pieces(map, t);
		}
		x = 0;
		while (x < t->width)
		{
			if (map->field[map->ycoord + y][map->xcoord + x] != '.'
					&& ft_isalpha(t->piece[y][x]))
			{
				map->xcoord++;
				test_pieces(map, t);
			}
			x++;
		}
		y++;
	}
	return(1);
}
