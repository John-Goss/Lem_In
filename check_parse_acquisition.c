/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_parse_acquisition.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jle-quer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/17 13:06:17 by jle-quer          #+#    #+#             */
/*   Updated: 2016/05/23 14:11:50 by jle-quer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	check_double_and_pos(t_room *room, t_room *begin)
{
	t_room	*ptr;

	ptr = begin;
	while (ptr->next)
	{
		if (room == ptr)
		{
			ptr = ptr->next;
			continue ;
		}
		if (ft_strcmp(room->name, ptr->name) == 0)
			ft_error("ERROR - DOUBLE ROOM NAME");
		if (room->x == ptr->x && room->y == ptr->y)
			ft_error("ERROR - SAME POSITION BETWEEN TWO ROOMS");
		ptr = ptr->next;
	}
}

/*int		check_acquisition(t_map *map)
{
	//Check link between start & end.
	t_room	*ptr;

	ptr = map->start;
	while (ptr && ptr != map->end)
	{
		
	}
	return (1);
}*/
