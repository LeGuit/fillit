/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwoodwar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/04 16:08:24 by gwoodwar          #+#    #+#             */
/*   Updated: 2016/01/08 12:21:06 by gwoodwar         ###   ########.fr       */
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
	map->minsquare = 8;
	map->xcoord = 0;
	map->ycoord = 0;
}

void			recursive(t_map *map, t_list **lst)
{
	while (*lst)
	{
		while (map->ycoord < map->minsquare)
		{
			while (map->xcoord < map->minsquare)
			{
				print_map(map);
				if (can_fit(map, CONTENT(*lst)))
				{
					if (!(*lst = (*lst)->next))
						return ;
					continue ;
				}
				map->minsquare += 1;
			//	(map, head);
				map->xcoord++;
			}
			map->ycoord++;
		}
	}
}

void			start_solve(t_list **lst)
{
	t_map		map;

	gen_map(&map);
	recursive(&map, lst);
	print_map(&map);
}

