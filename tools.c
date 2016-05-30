/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jle-quer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/16 16:16:04 by jle-quer          #+#    #+#             */
/*   Updated: 2016/05/26 17:21:21 by jle-quer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_map		*init_map(void)
{
	t_map	*new;

	if (!(new = (t_map *)malloc(sizeof(t_map))))
		return (NULL);
	new->start = NULL;
	new->end = NULL;
	new->top = NULL;
	new->ants = 0;
	new->rooms = 0;
	return (new);
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
	t_list	*ptr;

	ptr = room->neighbor;
	while (ptr)
	{
		if (ft_strcmp(ptr->content, name) == 0)
			return (0);
		ptr = ptr->next;
	}
	return (1);
}
