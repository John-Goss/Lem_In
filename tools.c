/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jle-quer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/16 16:16:04 by jle-quer          #+#    #+#             */
/*   Updated: 2016/05/24 16:04:42 by jle-quer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void		init_map(t_map *map)
{
	map->start = NULL;
	map->end = NULL;
	map->top = NULL;
	map->ants = 0;
	map->rooms = 0;
}

t_room		*init_room(void)
{
	t_room	*new;

	new = NULL;
	if (!(new = (t_room *)malloc(sizeof(t_room))))
		return (NULL);
	new->ant = 0;
	new->name = NULL;
	new->x = 0;
	new->y = 0;
	new->to_end = 0;
	new->nbr_neigh = 0;
	new->neighbor = NULL;
	new->next = NULL;
	return (new);
}

int			init_neighbors(t_neighbors *new)
{
	new = NULL;
	if (!(new = (t_neighbors *)malloc(sizeof(t_neighbors))))
		return (-1);
	new->name = NULL;
	new->next = NULL;
	return (1);
}

void		free_array(char **array)
{
	int	i;

	i = 0;
	while (array[i])
		i++;
	i--;
	while (i != 0)
		free(array[i--]);
	free(*array);
	free(array);
}

int			check_neighbors(t_room *room, char *name)
{
	t_room	*ptr;

	ptr = room;
	while (ptr->neighbor)
	{
		if (ft_strcmp(ptr->neighbor->name, name) == 0)
			return (0);
		ptr->neighbor = ptr->neighbor->next;
	}
	return (1);
}
