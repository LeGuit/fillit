/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   processing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwoodwar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/04 14:42:23 by gwoodwar          #+#    #+#             */
/*   Updated: 2015/12/08 21:09:51 by ndelmatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
/*
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
//	ft_putstr(tetri->piece);
	if (!is_valid(tetri->piece))
		return (-2);
	return (ret);
}
*/
int				get_next_tetri(int const fd, t_list **head)
{
	int				ret;
	char			buf[22];
	int				resval;

	(void)head;
	ret = read(fd, buf, 21);
	buf[ret] = '\0';
//OK	ft_putstr(buf);
	if(!(resval = is_valid(buf)) && *buf)///!\ *buf
	{
		ft_putnbr(resval);
		return (-1);
	}
//		ft_putnbr(resval);
//	if (!(tetri = create_piece(letter, head)))
//		return (-1);
	return (ret);
}
