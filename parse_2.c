/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jle-quer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/12 12:47:35 by jle-quer          #+#    #+#             */
/*   Updated: 2016/05/24 17:24:44 by jle-quer         ###   ########.fr       */
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

static void	set_2nd_room_neighbor(t_room *top, char **array)
{
	t_neighbors	*new;

	new = NULL;
	while (ft_strcmp(top->name, array[1]) != 0 && top)
		top = top->next;
	if (!check_neighbors(top, array[0]))
		return ;
	init_neighbors(new);
	if (top->neighbor)
		new->next = top->neighbor;
	top->neighbor = new;
	new->name = ft_strdup(array[0]);
	top->nbr_neigh++;
}

static void	set_room_link(t_room *top, char **array)
{
	t_room		*first;
	t_room		*second;
	t_neighbors	*new;

	first = top;
	second = top;
	new = NULL;
	while (ft_strcmp(first->name, array[0]) != 0 && first)
		first = first->next;
	while (ft_strcmp(second->name, array[1]) != 0 && second)
		second = second->next;
	if (!check_neighbors(first, array[1]))
		return ;
	if (ft_strcmp(first->name, array[0]) == 0 &&
			ft_strcmp(second->name, array[1]) == 0)
	{
		init_neighbors(new);
		if (first->neighbor)
			new->next = first->neighbor;
		new->name = ft_strdup(array[1]);
		first->nbr_neigh++;
		first->neighbor = new;
		set_2nd_room_neighbor(top, array);
	}
	else
		ft_error("ERROR");
}

void		chained_list_set(t_room *room, t_map *map)
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
