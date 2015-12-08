/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_patern.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwoodwar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/08 12:38:51 by gwoodwar          #+#    #+#             */
/*   Updated: 2015/12/08 12:38:53 by gwoodwar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int		patern_vl_vb(int len, t_tetri tetri)
{
	int		i;

	i = 0;
	while (PAT(i))
	{
		if (PAT(i) == '#' && PAT(i + len) == '#' && PAT(i + 2 * len) == '#')
		{
			if (PAT(i + 3 * len) == '#')
				return (1); //vertical bar
			else if (PAT(i + 2 * len + 1) == '#')
				return (5); // L tetri
			else if (PAT(i + 2 * len - 1) == '#')
				return (6); // rev L
			else if (PAT(i + 1) == '#')
				return (3); // top right L
			else if (PAT(i - 1) == '#')
				return (4); // top left L
		}
		i++;
	}
		return (0);
}

static int		patern_hl_hb(int len, t_tetri tetri)
{
	int		i;

	i = 0;
	while (PAT(i))
	{
		if (PAT(i) == '#' && PAT(i + 1) == '#' && PAT(i + 2) == '#')
		{
			if (PAT(i + 4) == '#')
				return (2); //horizontal bar
			else if (PAT(i + len) == '#')
				return (11); // hL tetri bot left
			else if (PAT(i + len + 2) == '#')
				return (13); // hL bot rigth
			else if (PAT(i - len) == '#')
				return (12); // hL top left
			else if (PAT(i - len + 2) == '#')
				return (14); // hL top right
		}
		i++;
	}
	return (0);
}

static int		patern_hz_ht_sq(int len, t_tetri tetri)
{
	int		i;

	i = 0;
	while (PAT(i))
	{
		if (PAT(i) == '#' && PAT(i + 1) == '#')
		{
			if (PAT(i + len + 1) && PAT(i + len + 2) == '#')
				return (16); //z
			else if (PAT(i + len + 1) == '#' && PAT(i + 2) == '#')
				return (17); // T
			else if (PAT(i + len) == '#' && PAT(i + len - 1) == '#')
				return (15); // rev z
			else if (PAT(i + 2) == '#' && PAT(i - len + 1) == '#')
				return (18); // rev T
			else if (PAT(i + len) == '#' && PAT(i + len + 1) == '#')
				return (19); // square
		}
		i++;
	}
	return (0);
}

static int		patern_vz_vt(int len, t_tetri tetri)
{
	int		i;

	i = 0;
	while (PAT(i))
	{
		if (PAT(i) == '#' && PAT(i + len) == '#')
		{
			if (PAT(i + len - 1) && PAT(i + 2 * len - 1) == '#')
				return (8); //vZ top right
			else if (PAT(i + len + 1) == '#' && PAT(i + 2 * len + 1) == '#')
				return (7); // vZ top left
			else if (PAT(i + len + 1) == '#' && PAT(i + 2 * len) == '#')
				return (9); // vT right
			else if (PAT(i + len - 1) == '#' && PAT(i + 2 * len) == '#')
				return (10); // vT left
		}
		i++;
	}
	return (0);
}

int				get_patern(int len, t_tetri tetri)
{
	int		res;

	if (res = patern_vl_vb(len, tetri)
			|| res = patern_hl_hb(len, tetri)
			|| res = patern_hz_ht_sq(len, tetri)
			|| res = patern_vz_vt(len, tetri))
		return (res);
	return (0);
}
