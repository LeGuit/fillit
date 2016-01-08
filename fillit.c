/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwoodwar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/03 15:41:29 by gwoodwar          #+#    #+#             */
/*   Updated: 2016/01/08 12:06:23 by gwoodwar         ###   ########.fr       */
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
	head = 0;
	if ((fd = open(av, O_RDONLY)) == -1)
		return (0);
	nbread = 0;
	while ((ret = get_next_tetri(fd, &head, letter)) > 0)
	{
		nbread += ret;
		letter++;
	}
	ft_lstrev(&head);
	if ((nbread - 20) % 21)//test a deplacer si possible
	   return (-1);	
	if (close(fd) == -1)
		return (0);
	start_solve(&head);
	return (1);
}
