/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_empty.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwoodwar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/08 12:53:15 by gwoodwar          #+#    #+#             */
/*   Updated: 2015/12/08 13:07:38 by gwoodwar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int		is_empty_1(char *map, int patern, int len)
{
	if (patern == 1 && map[i] == '.' && map
}

int				is_empty(t_map map, t_tetri tetri)
{
	if (is_empty_1(map->map, tetri.patern, map.len))
			return (1);
	return (0);
}
