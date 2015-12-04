/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwoodwar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/03 15:41:29 by gwoodwar          #+#    #+#             */
/*   Updated: 2015/12/04 15:05:57 by gwoodwar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int			fillit(char *av)
{
	int		fd;
	int		ret;
	char	letter;
//	char	*line;
	t_list	*head;

	head = NULL;
	if ((fd = open(av, O_RDONLY)) == -1)
		return (0);
	letter = 'A';
	while ((ret = get_next_tetri(fd, letter, &head)) > 0)
		letter++;
	if (ret == -1)
		return (0);
//	if (get_line(fd, &line))
//		ft_putstr("pass");
	if (close(fd) == -1)
		return (0);
	return (1);
}
