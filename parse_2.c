/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jle-quer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/12 12:47:35 by jle-quer          #+#    #+#             */
/*   Updated: 2016/05/20 15:15:13 by jle-quer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static int	check_exist_room(char *first, char *last, t_room *top)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (ft_strcmp(first, last) == 0)
		ft_error("ERROR");
	while (top)
	{
		if (ft_strcmp(first, top->name) == 0)
			i++;
		if (ft_strcmp(last, top->name) == 0)
			j++;
		if (i == 1 && j == 1)
			return (1);
		top = top->next;
	}
	ft_error("ERROR");
	return (0);
}

static void	chained_list_set(t_room *room, t_map *map)
{
	t_room	*ptr;

	ptr = NULL;
	if (map->rooms == 1)
	{
		room->next = NULL;
		map->top = room;
	}
	else
	{
		ptr = map->top;
		while (ptr->next)
			ptr = ptr->next;
		ptr->next = room;
		room->next = NULL;
	}
	check_double_and_pos(room, map->top);
}

static void	set_room_link(t_room *top, char **array)
{
	t_room		*cur;
	t_room		*tmp;
	t_neighbors	*new;

	tmp = top;
	cur = top;
	new = init_neighbors();
	while (ft_strcmp(cur->name, array[0]) != 0 && cur)
		cur = cur->next;
	while (ft_strcmp(tmp->name, array[1]) != 0 && tmp)
		tmp = tmp->next;
	if (ft_strcmp(cur->name, array[0]) == 0 &&
			ft_strcmp(tmp->name, array[1]) == 0)
	{
		if (cur->neighbor)
			new->next = cur->neighbor;
		new->name = ft_strdup(array[1]);
		cur->nbr_neigh++;
		cur->neighbor = new;
	}
	else
		ft_error("ERROR");
}

int			parse_room(t_room *room, t_map *map, char *line, int type)
{
	char	**array;
	int		i;

	i = 0;
	array = ft_strsplit(line, ' ');
	while (array[i])
		i++;
	if (i != 3 || !ft_isint(array[1]) || !ft_isint(array[2]))
		return (0);
	room->name = ft_strdup(array[0]);
	room->x = ft_atoi(array[1]);
	room->y = ft_atoi(array[2]);
	map->rooms++;
	if (type == 0)
	{
		room->ant = map->ants;
		map->start = &(*room);
	}
	else if (type == 1)
		map->end = room;
	chained_list_set(room, map);
	free_array(array);
	return (1);
}

int			get_room_link(t_map *map, char *line)
{
	int			i;
	char		**array;

	i = 0;
	array = ft_strsplit(line, '-');
	while (array[i])
		i++;
	if (i != 2 || !check_exist_room(array[0], array[1], map->top))
		return (0);
	set_room_link(map->top, array);
	return (1);
}
