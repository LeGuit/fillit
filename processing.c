/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   processing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwoodwar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/04 14:42:23 by gwoodwar          #+#    #+#             */
/*   Updated: 2015/12/04 17:52:47 by gwoodwar         ###   ########.fr       */
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
//	(tetri->piece)[ret] = 0;
	ft_putstr(tetri->piece);
	if (!is_valid(tetri->piece))
		return (-2);
	return (ret);
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
