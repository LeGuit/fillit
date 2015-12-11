/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opp_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndelmatt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/10 18:07:41 by ndelmatt          #+#    #+#             */
/*   Updated: 2015/12/11 15:27:17 by gwoodwar         ###   ########.fr       */
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
			if (ft_isalpha(t->piece[y][x]))
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
			if (ft_isalpha(t->piece[y][x]))
				map->field[y + map->ycoord][x + map->xcoord] = '.';
		}
		x++;
	}
	y++;
}

int				can_fit_there(t_map *map, t_list *lst)
{
	int         x;
	int         y;

	y = 0;
	while (y < t->height)
	{
		x = 0;
		while (x < t->width)
		{
			if (map->field[map->ycoord + y][map->xcoord + x] != '.'
					&& ft_isalpha(t->piece[y][x]))
				return (0);
			x++;
		}
		y++;
	}
	return(1);
}

int				can_fit(t_map *map, t_list *lst)
{
	int			xstart;

	xstart = map->xcoord;
	while (map->ycoord < map->minsquare)
	{
		while (map->xcoord < map->minsquare)
		{
			if (!can_fit_there(map, lst))
			{
				if (map->xcoord < map->minsquare)
					map->xcoord++;
				else
				{
					map->xcoord = xstart;
					map->ycoord++;
				}
			}
			else
			{
				insert_piece(map, CONTENT(lst));
				return (1);
			}
		}
	}
	return (0);
}





