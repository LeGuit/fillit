/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwoodwar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/03 11:35:24 by gwoodwar          #+#    #+#             */
/*   Updated: 2016/01/07 17:13:48 by gwoodwar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _FILLIT_H
# define _FILLIT_H

# include "libft/includes/libft.h"
# define P_SIZE			4
# define CONTENT(x)		((t_tetri *)(x)->content)
# define PAT(x)			ft_isalpha(((tetri.piece)[x]))
# define MAP_SIZE		128

typedef struct		s_tetri
{
	char			letter;
	char			piece[P_SIZE][P_SIZE];
	int				height;
	int				width;
	int				xmin;
	int				xmax;
	int				ymin;
	int				ymax;
	int				mempos[2];
}					t_tetri;

typedef struct		s_map
{
	char			field[MAP_SIZE][MAP_SIZE];
	int				minsquare;
	int				xcoord;
	int				ycoord;
}					t_map;

int					is_valid(char *buf);
int					fillit(char*av);
int					get_next_tetri(int const fd, t_list **head, char letter);
void				mapgen(t_map *map);
void				print_piece(t_tetri const *t);
void				print_map(t_map *map);
void				start_solve(t_list **lst);
void				recursive(t_map *map, t_list *lst);
int					can_fit(t_map *map, t_tetri *t);
#endif
