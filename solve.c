/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwoodwar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/04 16:08:24 by gwoodwar          #+#    #+#             */
/*   Updated: 2015/12/10 18:50:13 by ndelmatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void			find_space(t_map *map, t_list **head)
{
	map->ycoord = 0;
	while (map->ycoord < map->minsquare)
	{
		map->xcoord = 0;
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
	print_solution();
}

int				test_pieces(t_map *map, t_tetri *t)
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
