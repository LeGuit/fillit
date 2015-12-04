/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwoodwar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/03 15:41:29 by gwoodwar          #+#    #+#             */
/*   Updated: 2015/12/04 17:44:21 by gwoodwar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int			fillit(char *av)
{
	int		fd;
	int		ret;
	char	letter;
	t_list	*head;

	head = NULL;
	if ((fd = open(av, O_RDONLY)) == -1)
		return (0);
	letter = 'A';
	while ((ret = get_next_tetri(fd, letter, &head)) > 0)
	{
//		ft_putstr(CONTENT(head)->piece);
//		ft_putnbr(CONTENT(head)->width);
//		ft_putnbr(CONTENT(head)->height);
		letter++;
	}
ft_putstr("test ret : ");
	ft_putnbr(ret);
//	if (ret == -2)
//		return (0);
	if (close(fd) == -1)
		return (0);
//	solve(&head);
	return (1);
}
