/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   processing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwoodwar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/04 14:42:23 by gwoodwar          #+#    #+#             */
/*   Updated: 2015/12/04 15:08:20 by gwoodwar         ###   ########.fr       */
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

	while ((ret = read(fd, tetri->piece, BUFF_SIZE)) > 0)
	{
		(tetri->piece)[ret] = 0;
		if (!is_valid(tetri->piece))
			return (-1);
	}
	return (ret);
}

int				get_next_tetri(int const fd, char letter, t_list **head)
{
	t_tetri			*tetri;
	int				ret;

	if (fd < 0 || BUFF_SIZE < 1)
		return (-1);
	*head = 0;
	if (!(tetri = create_piece(letter, head)))
		return (-1);
	ret = read_in_fd(fd, tetri);
	return (ret);
}
