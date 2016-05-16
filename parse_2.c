/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jle-quer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/12 12:47:35 by jle-quer          #+#    #+#             */
/*   Updated: 2016/05/16 18:29:16 by jle-quer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static int	check_exist_room(char *first, char *last, t_room *top)
{
	int	i;

	i = 0;
	while (top)
	{
		if (ft_strcmp(first, top->name) == 0)
			i++;
		if (ft_strcmp(last, top->name) == 0)
			i++;
		if (i == 2)
			return (1);
		top = top->next;
	}
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
}

static void	set_room_link(t_room *top, t_neighbors *voisin, char **array)
{
	t_room	*cur;
	t_room	*tmp;

	tmp = top;
	cur = top;
	voisin = init_neighbors();
	while (ft_strcmp(cur->name, array[0]) != 0 || !cur)
		cur = cur->next;
	while (ft_strcmp(tmp->name, array[1]) != 0 || !tmp)
		tmp = tmp->next;
	if (ft_strcmp(cur->name, array[0]) == 0 && ft_strcmp(tmp->name, array[1]) == 0)
	{
		if (voisin->nbr_neigh > 0)
			voisin->next = cur->neighbor;
		voisin->name = ft_strdup(array[1]);
		voisin->nbr_neigh++;
		cur->neighbor = voisin;
	}
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
	t_neighbors	*new;
	int			i;
	char		**array;

	i = 0;
	new = NULL;
	array = ft_strsplit(line, '-');
	while (array[i])
		i++;
	if (i != 2 || !check_exist_room(array[0], array[1], map->top))
		return (0);
	set_room_link(map->top, new, array);
	return (1);
}
