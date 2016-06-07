/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jle-quer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/16 16:16:04 by jle-quer          #+#    #+#             */
/*   Updated: 2016/06/07 11:38:21 by jle-quer         ###   ########.fr       */
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
	new->tab = NULL;
	new->node = NULL;
	new->path = NULL;
	new->line = NULL;
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

t_tab		*init_tab(char *name, int left)
{
	t_tab	*new;

	new = NULL;
	if (!(new = (t_tab *)malloc(sizeof(t_tab))))
		return (NULL);
	new->name = ft_strdup(name);
	new->left = left;
	new->passed = 0;
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
