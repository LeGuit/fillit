/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   processing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwoodwar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/04 14:42:23 by gwoodwar          #+#    #+#             */
/*   Updated: 2015/12/09 21:58:20 by ndelmatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static void		create_piece(t_list **head, char *buf, char letter)
{
	t_list		*node;
	t_tetri		contentnew;
	int			i;
	int			j;

	i = 0;
	j = 0;
	while (i < 19)
	{
		if (buf[i] != '\n')
		{
			if (buf[i] == '#')
				contentnew.piece[j] = letter;
			else
				contentnew.piece[j] = buf[i];
			j++;
		}
		i++;
	}
	contentnew.piece[j] = '\0';
	contentnew.letter = letter;
	if (!(node = ft_lstnew(&contentnew, sizeof(t_tetri))))
		return ;
	ft_lstadd_last(head, node);
}

int				get_next_tetri(int const fd, t_list **head, char letter)
{
	int			ret;
	char		buf[22];
	int			resval;

	(void)head;
	ret = read(fd, buf, 21);
	buf[ret] = '\0';
//	ft_putstr(buf);
	if(!(resval = is_valid(buf)) && *buf)///!\ *buf
	{
		ft_putnbr(resval);
		return (-1);
	}
	create_piece(head, buf, letter);
	return (ret);
}
