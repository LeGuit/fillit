/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwoodwar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/03 15:41:29 by gwoodwar          #+#    #+#             */
/*   Updated: 2016/01/11 14:59:20 by gwoodwar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int				fillit(char *av)
{
	int			fd;
	int			ret;
	t_list		*head;
	int			nbread;
	char		letter;

	letter = 'A';
	head = 0;
	if ((fd = open(av, O_RDONLY)) == -1)
		return (0);
	nbread = 0;
	ret = 1;
	while (ret > 0)
	{
		ret = get_next_tetri(fd, &head, letter);
		nbread += ret;
		letter++;
	}
	ft_lstrev(&head);
	if ((nbread - 20) % 21)//test a deplacer si possible
	   return (0);	
	if (close(fd) == -1)
		return (0);
	start_solve(&head);
	return (1);
}
