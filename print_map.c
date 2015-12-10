/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndelmatt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/10 17:37:37 by ndelmatt          #+#    #+#             */
/*   Updated: 2015/12/10 17:47:12 by ndelmatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void			print_map(t_map *map)
{
	int	x;
	int y;

	x = 0;
	y = 0;
	while (y < map->minsquare)
	{
		while (x < map->minsquare)
		{
			ft_putchar(map->field[y][x]);
			x++;
		}
		y++;
		ft_putchar('\n');
		x = 0;
	}
}

