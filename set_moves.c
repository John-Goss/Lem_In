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
/*
static int	nbr_room_path(t_map *map)
{
	int		i;
	t_list	*tmp;

	i = 0;
	tmp = map->path;
	while (tmp)
	{
		i++;
		tmp = tmp->next;
	}
	return (i);
}
*/
static void	set_rooms_neighbors(t_map *map)
{
	t_room	*ptr;
	t_room	*neigh;
	t_list	*lst;

	ptr = map->start;
	lst = map->path;
	while (lst->next)
	{
		neigh = map->top;
		while (ft_strcmp(neigh->name, lst->next->content) != 0)
			neigh = neigh->next;
		ptr->next = neigh;
		ptr = ptr->next;
		lst = lst->next;
	}
}

static void	moves_ope(t_room *room)
{
	if (room->next->ant == 0)
		return ;
	if (end || room vide)
		avance
	else
		recursive sur room->next
}

void		set_moves(t_map **map)
{
	set_rooms_neighbors((*map));
	(*map)->start->ant = (*map)->ants;
	moves_ope((*map)->start);
}
