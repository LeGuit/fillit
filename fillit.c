/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwoodwar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/03 15:41:29 by gwoodwar          #+#    #+#             */
/*   Updated: 2015/12/08 20:36:59 by ndelmatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int			fillit(char *av)
{
	int		fd;
	int		ret;
	t_list	*head;
	int		nbread;

	head = NULL;
	if ((fd = open(av, O_RDONLY)) == -1)
		return (0);
	nbread = 0;
	while ((ret = get_next_tetri(fd, &head)) > 0)
		nbread += ret;
	if ((nbread - 20) % 21)//test a deplacer si possible
	   return (-1);	
//	if (ret == -2)
//		return (0);
	if (close(fd) == -1)
		return (0);
//	solve(&head);
	return (1);
}
