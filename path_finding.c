/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_finding.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jle-quer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/31 14:34:05 by jle-quer          #+#    #+#             */
/*   Updated: 2016/06/02 14:03:25 by jle-quer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static t_list	*find_neighbor(t_list *room, t_room *top)
{
	t_list	*ret;
	t_room	*ptr;

	ret = NULL;
	ptr = top;
	while (ptr)
	{
		if (ft_strcmp(ptr->name, ((t_tab *)room->content)->name) == 0)
			ret = ptr->neighbor;
		ptr = ptr->next;
	}
	return (ret);
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

	neighbor = NULL;
	start = find_start((*map)->tab);
	while (start)
	{
		if (!(neighbor = find_neighbor(start, (*map)->top)))
			return (0);
//		if (unused_neighbor(neighbor, (*map)->tab))
//		{
//		
//		}
	}
	return (1);
}
