/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwoodwar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/04 16:08:24 by gwoodwar          #+#    #+#             */
/*   Updated: 2015/12/04 17:07:44 by gwoodwar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void			solve(t_list **head)
{
	t_list *tmp;

	tmp = *head
		while (tmp)
		{
			get_size_piece(CONTENT(head));
			tmp = tmp->next;
		}

}

static void		get_size_piece(t_tetri *tetri)
{
	int		i;

	i = -1;
	while ((tetri->piece)[++i])
	{
		if (isalpha((tetri->piece)[i]))
		{
			tetri.xmin = i % 5;
			tetri.ymin = i / 5;
			break ;
		}
	}
	i = 21
	while ((tetri->piece)[--i])
	{
		if (isalpha((tetri->piece)[i]))
		{
			tetri.width = i % 5;
			tetri.height = i / 5;
			break ;
		}
	}
	tetri.width -= (tetri.x - 1);
	tetri.height -= (tetri.y - 1);
}
