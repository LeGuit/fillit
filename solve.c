/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwoodwar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/04 16:08:24 by gwoodwar          #+#    #+#             */
/*   Updated: 2016/01/11 16:14:32 by gwoodwar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int		min_square(int nb)
{
	int			i;

	i = 1;
	while ((i * i) < (nb * 4))
		i++;
	return (i);
}

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
	map->xcoord = 0;
	map->ycoord = 0;
}

void			start_solve(t_list **lst)
{
	t_map		map;
	int			size;
	t_list		*tmp;

	size = 0;
	tmp = *lst;
	while (tmp)
	{
		size++;
		tmp = tmp->next;
	}
	map.minsquare = min_square(size);
	gen_map(&map);
	algo(&map, lst);
	print_map(&map);
}
