/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   processing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwoodwar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/03 13:02:14 by gwoodwar          #+#    #+#             */
/*   Updated: 2015/12/03 13:09:08 by gwoodwar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int		get_tetrinos(int const fd, char **line)
{
	int		ret;
	char	buf[BUFF_SIZE];

	ret = read(fd, buf, BUFF_SIZE + 2) //to put a \n then a \0 to avec %21
	buf[ret] = 0;
	buf[ret - 1] = '\n';
	if ((!(*line = ft_strjoin(*line, buf))) || read(fd, buf, 1))
		return (0);
	return (1);
}

static char		*symb_to_ascii(char *line)
{
	char	let;
	size_t	it;
	int		count;

	it = 0;
	count = 0;
	let = 'A';
	while (it < ft_strlen(line))
	{
		if (line[i] == '#')
		{
			line[i] = let;
			count++;
		}
		if (count != 0 && count % 4 = 0)
			let++;
	}
	return (line);
}
