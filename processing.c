/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   processing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwoodwar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/04 14:42:23 by gwoodwar          #+#    #+#             */
/*   Updated: 2016/01/11 18:23:03 by ndelmatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static void		gen_piece(t_tetri *tetri)
{
	int			x;
	int			y;

	y = -1;
	while (++y < P_SIZE)
	{
		x = -1;
		while (++x < P_SIZE)
		{
			tetri->piece[y][x] = '.';
		}
	}
}

static void		get_piece_metrics(char *buf, t_tetri *t)
{
	int			x;
	int			y;

	y = 0;
	t->xmin = 4;
	t->xmax = 0;
	t->ymin = 4;
	t->ymax = 0;
	while (y < 4)
	{
		x = 0;
		while (x < 4)
		{
			if (buf[y * 5 + x] == '#')
			{
				t->xmin = MIN(t->xmin, x);
				t->xmax = MAX(t->xmax, x);
				t->ymin = MIN(t->ymin, y);
				t->ymax = MAX(t->ymax, y);
			}
			x++;
		}
		y++;
	}
}

static void		buf_to_struct(char *buf, t_tetri *t)
{
	int			x;
	int			y;

	y = 0;
	while (y < t->height)
	{
		x = 0;
		while (x < t->width)
		{
			if (buf[x + t->xmin + (y + t->ymin) * 5] == '#')
				t->piece[y][x] = t->letter;
			x++;
		}
		y++;
	}
}

static void		create_piece(t_list **head, char *buf, char letter)
{
	t_list		*node;
	t_tetri		t;

	gen_piece(&t);
	get_piece_metrics(buf, &t);
	t.letter = letter;
	t.height = t.ymax - t.ymin + 1;
	t.width = t.xmax - t.xmin + 1;
	buf_to_struct(buf, &t);
	if (!(node = ft_lstnew(&t, sizeof(t_tetri))))
		return ;
	ft_lstadd(head, node);
}

int				get_next_tetri(int const fd, t_list **head, char letter)
{
	int			ret;
	char		buf[22];
	int			resval;

	ret = read(fd, buf, 21);
	buf[ret] = '\0';
	if (!(resval = is_valid(buf)) && *buf)
		return (0);
	if (ret != 0)
		create_piece(head, buf, letter);
	return (ret);
}
