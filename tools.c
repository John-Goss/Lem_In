/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jle-quer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/16 16:16:04 by jle-quer          #+#    #+#             */
/*   Updated: 2016/05/17 12:20:26 by jle-quer         ###   ########.fr       */
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

t_neighbors	*init_neighbors(void)
{
	t_neighbors	*new;

	new = NULL;
	if (!(new = (t_neighbors *)malloc(sizeof(t_neighbors))))
		return (NULL);
	new->name = NULL;
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
