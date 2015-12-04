/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwoodwar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/03 11:35:24 by gwoodwar          #+#    #+#             */
/*   Updated: 2015/12/04 16:57:02 by gwoodwar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _FILLIT_H
# define _FILLIT_H

# include "libft/includes/libft.h"
# define BUFF_SIZE		21
# define CONTENT(x)		((t_tetri *)(x)->content)

int					is_valid(char *line);
int					fillit(char*av);
//int					get_line(int const fd, char **line);
int					get_next_tetri(int const fd, char letter, t_list **head);

typedef struct		s_tetri
{
	char			letter;
	char			*piece;
	int				height;
	int				width;
}					t_tetri;

#endif
