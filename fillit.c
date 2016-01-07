/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwoodwar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/03 15:41:29 by gwoodwar          #+#    #+#             */
/*   Updated: 2016/01/07 17:29:08 by gwoodwar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int			fillit(char *av)
{
	int		fd;
	int		ret;
	t_list	*head;
	int		nbread;
	char	letter;

	letter = 'A';
	head = NULL;
	if ((fd = open(av, O_RDONLY)) == -1)
		return (0);
	nbread = 0;
	while ((ret = get_next_tetri(fd, &head, letter)) > 0)
	{
		nbread += ret;
		letter++;
		print_piece(CONTENT(head));
		ft_putendl("");
//i		ft_putendl(CONTENT(head)->piece[3]);
	}
	if ((nbread - 20) % 21)//test a deplacer si possible
	   return (-1);	
	if (close(fd) == -1)
		return (0);
	start_solve(&head);
	return (1);
}
