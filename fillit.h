/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwoodwar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/03 11:35:24 by gwoodwar          #+#    #+#             */
/*   Updated: 2015/12/08 13:01:50 by gwoodwar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _FILLIT_H
# define _FILLIT_H

# include "libft/includes/libft.h"
# define BUFF_SIZE		21
# define CONTENT(x)		((t_tetri *)(x)->content)
# define PAT(x)			((tetri.piece)[x])

int					is_valid(char *line);
int					fillit(char*av);
int					get_next_tetri(int const fd, char letter, t_list **head);

typedef struct		s_tetri
{
	char			letter;
	char			*piece;
	int				height;
	int				width;
	int				patern;
}					t_tetri;

typedef struct		s_map
{
	char			*map;
	int				lenline;
	int				minheight;
	int				minwidth;
}					t_map;

#endif
