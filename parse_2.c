/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jle-quer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/12 12:47:35 by jle-quer          #+#    #+#             */
/*   Updated: 2016/05/15 19:26:12 by jle-quer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void	chained_list_set(t_room *room, t_map *map)
{
	t_room	*ptr;

	ptr = NULL;
	if (map->start == NULL)
	{
		if (room->top == NULL)
			room->top = room;
		ptr = room->top;
	}
	else
		ptr = map->start;
	if (g_first == 0)
	{
		room->next = NULL;
		room->prev = NULL;
	}
	else
	{
		room->next = NULL;
		while (ptr->next)
			ptr = ptr->next;
		room->prev = ptr;
		ptr->next = room;
	}
}

void		init_map(t_map *map)
{
	map->start = NULL;
	map->end = NULL;
	map->ants = 0;
	map->rooms = 0;
}

void		parse_room(t_room *room, t_map *map, char *line, int type)
{
	char	**array;
	int		i;

	i = 0;
	array = ft_strsplit(line, ' ');
	while (array[i])
		i++;
	if (i != 3 || ft_isint(array[0]) == 0 || ft_isint(array[1]) == 0 || ft_isint(array[2]) == 0)
		ft_error("ERROR");
	room->name = array[0];
	room->x = ft_atoi(array[1]);
	room->y = ft_atoi(array[2]);
	map->rooms++;
	if (type == 0)
	{
		room->ant = map->ants;
		map->start = room;
	}
	else if (type == 1)
		map->end = room;
	chained_list_set(room, map);
}
