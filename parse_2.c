/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jle-quer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/12 12:47:35 by jle-quer          #+#    #+#             */
/*   Updated: 2016/05/12 20:39:44 by jle-quer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	is_start_end(t_room *room, t_map *map, char *line, int type)
{
	size_t	i;
	size_t	j;

	i = ft_strchr_index(line, ' ');
	if ((int)i == -1 || ft_isint(ft_strndup(line, i)) == 0)
		ft_error("ERROR");
	room->name = ft_strndup(line, i);
	j = ft_strchr_index(line + i + 1, ' ') + i;
	ft_isint(ft_strndup(line + i + 1, j - 1)) == 1 ?
		room->x = ft_atoi(ft_strndup(line + i, j)) : ft_error("ERROR");
	i = ft_strchr_index(line + j + 1, ' ') + j;
	ft_isint(ft_strndup(line + j + 2, i)) == 1 ?
		room->y = ft_atoi(ft_strndup(line + j + 2, i)) : ft_error("ERROR");
	map->rooms++;
	if (type == 0)
	{
		room->ant = map->ants;
		map->start = room;
	}
	else
		map->end = room;
	ft_printf("Name : {%s}\nX : {%d} /// Y : {%d}\nMap Rooms Numbers : {%d}\n", room->name, room->x, room->y, map->rooms);
}
