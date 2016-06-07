/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_moves.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jle-quer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/07 14:44:57 by jle-quer          #+#    #+#             */
/*   Updated: 2016/06/07 20:09:22 by jle-quer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void	set_rooms_neighbors(t_map **map)
{
	t_room	*ptr;
	t_room	*neigh;
	t_list	*lst;

	ptr = (*map)->start;
	lst = (*map)->path;
	while (lst->next)
	{
		neigh = (*map)->top;
		while (ft_strcmp(neigh->name, lst->next->content) != 0)
			neigh = neigh->next;
		ptr->next = neigh;
		neigh->prev = ptr;
		ptr = ptr->next;
		lst = lst->next;
	}
}

static void	moves_ope(t_map **map)
{
	t_room	*ptr;
	t_room	*prev;

	ptr = (*map)->end;
	while (ptr->prev)
	{
		prev = ptr->prev;
		if ((ptr == (*map)->end || ptr->ant == 0) && prev->ant > 0)
		{
			ft_printf("L%d-%s ", prev->ant, ptr->name);
			ptr->ant = prev->ant;
			prev->ant = 0;
		}
		ptr = ptr->prev;
	}
}

void		set_moves(t_map **map)
{
	int	nbr;

	nbr = 1;
	set_rooms_neighbors(map);
	(*map)->start->ant = (*map)->ants;
	while ((*map)->end->ant != (*map)->ants)
	{
		if (nbr <= (*map)->ants)
			(*map)->start->ant = nbr;
		moves_ope(map);
		if ((*map)->end->ant != (*map)->ants)
			ft_putchar('\n');
		nbr++;
	}
	ft_putchar('\n');
}
