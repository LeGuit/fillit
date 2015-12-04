/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   processing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwoodwar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/03 13:02:14 by gwoodwar          #+#    #+#             */
/*   Updated: 2015/12/04 11:05:16 by gwoodwar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int		get_tetrinos(int const fd, char **line)
{
	int		ret;
	char	buf[BUFF_SIZE];
	int		loop;
	char	*tmp;

	loop = 0;
	while (((ret = read(fd, buf, BUFF_SIZE)) > 0) && loop < 26)
	{
		buf[ret] = 0;
	ft_putendl("test buf : ");
	ft_putendl(buf);
		if (!is_valid(buf))
			return (0);
		tmp = *line;
		if (!(*line = ft_strjoin(tmp, buf)))
			return (0);
		free(tmp);
		loop++;
	}
	ft_putstr("test line : ");
	ft_putendl(*line);
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
		if (line[it] == '#')
		{
			line[it] = let;
			count++;
		}
		if (count != 0 && count % 4 == 0)
			let++;
		it++;
	}
	return (line);
}

int				get_line(int const fd, char **line)
{
	int		i;
	*line = 0;
	ft_putstr("test before get tetri\n");
	if (!get_tetrinos(fd, line) || !(i = is_valid(*line)))
		return (0);
	ft_putstr("test isvalid : ");
	ft_putnbr(i);
	*line = symb_to_ascii(*line);
	return (1);
}
