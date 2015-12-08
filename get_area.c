/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_area.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwoodwar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/08 12:39:13 by gwoodwar          #+#    #+#             */
/*   Updated: 2015/12/08 12:39:25 by gwoodwar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void		size_tetri(t_tetri tetri)
{
	if (tetri.patern == 1)
	{
		tetri.height = 4;
		tetri.width = 1;
	}
	else if (tetri.patern == 2)
	{
		tetri.height = 1;
		tetri.width = 4;
	}
	else if (tetri.patern >= 3 && tetri.patern <= 10)
	{
		tetri.height = 3;
		tetri.width = 2;
	}
	else if (tetri.patern >= 10 && tetri.patern <= 18)
	{
		tetri.height = 2;
		tetri.width = 3;
	}
	else
	{
		tetri.height = 2;
		tetri.width = 2;
	}
}
