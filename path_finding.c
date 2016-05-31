/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_finding.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jle-quer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/31 14:34:05 by jle-quer          #+#    #+#             */
/*   Updated: 2016/05/31 16:13:46 by jle-quer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static t_list	*set_neighbor_list(t_room *room, t_room *top)
{
	t_list	*ptr;

	ptr = NULL;

	return (ptr);
}

static t_list	*find_start(t_list *tab)
{
	t_list	*ptr;

	ptr = tab;
	while (((t_tab *)ptr->content)->left != 0 && ptr)
		ptr = ptr->next;
	if (ptr == NULL)
		return (NULL);
	return (ptr);
}

int				path_finding(t_map **map)
{
	t_list	*start;
	t_list	*neighbor;
	t_room	*room;

	neighbor = NULL;
	room = (*map)->start;
	start = find_start((*map)->tab);
	while (room)
	{
		neighbor = set_neighbor_list(room, (*map)->top);
	}
	return (1);
}
