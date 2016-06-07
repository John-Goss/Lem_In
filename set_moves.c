/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_moves.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jle-quer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/07 14:44:57 by jle-quer          #+#    #+#             */
/*   Updated: 2016/06/07 17:58:35 by jle-quer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static int		nbr_room_path(t_map *map)
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

void			set_moves(t_map **map)
{
	t_room	*dest;
	size_t	index_room;
	size_t	nbr;

	dest = NULL;
	nbr = nbr_room_path(*map);
	index_room = nbr;
	while ((*map)->path)
	{
		ft_printf("%s ", (*map)->path->content);
		(*map)->path = (*map)->path->next;
	}
	while (map->ants > 0)
	{
		dest = map->start;
		if (!(dest = find_room_move(map, index_room)))
			break ;
		if (dest->ant > 0)
			;
		ft_printf("L%d-%s ", dest->ant, dest->name);
	}
}
