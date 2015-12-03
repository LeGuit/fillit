/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwoodwar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/03 15:41:29 by gwoodwar          #+#    #+#             */
/*   Updated: 2015/12/03 19:00:26 by gwoodwar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int			fillit(char *av)
{
	int		fd;
	char	*line;

	if ((fd = open(av, O_RDONLY)) == -1)
		return (0);
	if (get_line(fd, &line))
		ft_putstr("pass");
//		ft_putstr(line);
	if (close(fd) == -1)
		return (0);
	return (1);
}
