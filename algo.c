/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwoodwar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/08 16:59:11 by gwoodwar          #+#    #+#             */
/*   Updated: 2016/01/11 17:21:46 by ndelmatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int			can_fit(t_map *map, t_list *lst)
{
	while (map->ycoord < map->minsquare)
	{
		while (map->xcoord < map->minsquare)
		{
			if (can_fit_there(map, lst))
				return (1);
			else
			{
				if (map->minsquare - map->xcoord >= CONTENT(lst)->width)
					map->xcoord++;
				else
					break ;
			}
		}
		if (map->minsquare - map->ycoord >= CONTENT(lst)->height)
		{
			map->xcoord = 0;
			map->ycoord++;
		}
		else
			break ;
	}
	return (0);
}

static int	insert_remove(t_map *map, t_list *lst)
{
	insert_piece(map, CONTENT(lst));
	if (lst->next)
	{
		if (!can_fit(map, lst->next))
		{
			remove_piece(map, CONTENT(lst));
			return (0);
		}
	}
	return (1);
}

int			can_fit_there(t_map *map, t_list *lst)
{
	int		x;
	int		y;

	if (CONTENT(lst)->height > (map->minsquare - map->ycoord)
			|| CONTENT(lst)->width > (map->minsquare - map->xcoord))
		return (0);
	y = 0;
	while (y < CONTENT(lst)->height)
	{
		x = 0;
		while (x < CONTENT(lst)->width)
		{
			if (map->field[map->ycoord + y][map->xcoord + x] != '.'
					&& ft_isalpha(CONTENT(lst)->piece[y][x]))
				return (0);
			x++;
		}
		y++;
	}
	if (!(insert_remove(map, lst)))
		return (0);
	return (1);
}

void		algo(t_map *map, t_list **lst)
{
	if (can_fit(map, *lst))
		return ;
	else
	{
		map->minsquare++;
		map->xcoord = 0;
		map->ycoord = 0;
		algo(map, lst);
	}
}
