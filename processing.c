/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   processing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwoodwar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/04 14:42:23 by gwoodwar          #+#    #+#             */
/*   Updated: 2015/12/04 17:09:28 by gwoodwar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static t_tetri	*create_piece(char letter, t_list **head)
{
	t_list	*node;
	t_tetri	contentnew;

	contentnew.letter = letter;
	contentnew.piece = ft_strnew(BUFF_SIZE);
	if (!(node = ft_lstnew(&contentnew, sizeof(t_tetri))))
	{
		free(contentnew.piece);
		return (NULL);
	}
	ft_lstadd_last(head, node);
	return (CONTENT(node));
}

static int		read_in_fd(int const fd, t_tetri *tetri)
{
	int		ret;

	ret = read(fd, tetri->piece, BUFF_SIZE);
	(tetri->piece)[ret] = 0;
	if (!is_valid(tetri->piece))
		return (-2);
	get_size_piece(tetri);
	return (ret);
}

static void		get_size_piece(t_tetri *tetri)
{
	int		i;

	i = -1;
	while ((tetri->piece)[++i])
	{
		if (isalpha((tetri->piece)[i]))
		{
			tetri.xmin = i % 5;
			tetri.ymin = i / 5;
			break ;
		}
	}
	i = 21
		while ((tetri->piece)[--i])
		{
			if (isalpha((tetri->piece)[i]))
			{
				tetri.width = i % 5;
				tetri.height = i / 5;
				break ;
			}
		}
	tetri.width -= (tetri.x - 1);
	tetri.height -= (tetri.y - 1);
}

int				get_next_tetri(int const fd, char letter, t_list **head)
{
	t_tetri			*tetri;
	int				ret;

	if (fd < 0 || BUFF_SIZE < 1)
		return (-1);
	if (!(tetri = create_piece(letter, head)))
		return (-1);
	ret = read_in_fd(fd, tetri);
	return (ret);
}
