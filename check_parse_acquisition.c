/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_parse_acquisition.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jle-quer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/17 13:06:17 by jle-quer          #+#    #+#             */
/*   Updated: 2016/06/06 21:15:09 by jle-quer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void		check_double_and_pos(t_room *room, t_room *begin)
{
	t_room	*ptr;

	ptr = begin;
	while (ptr->next)
	{
		if (ptr == room)
		{
			ptr = ptr->next;
			continue ;
		}
		if (ft_strcmp(room->name, ptr->name) == 0)
			ft_error("ERROR - DOUBLE ROOM NAME");
		if (room->x == ptr->x && room->y == ptr->y)
			ft_error("ERROR - SAME POSITION BETWEEN TWO ROOMS");
		ptr = ptr->next;
	}
}

static void	set_node(t_list **node, t_map **map)
{
	t_room	*tmp;

	tmp = (*map)->top;
	while (tmp)
	{
		if ((*node) == NULL)
			(*node) = ft_lstnew(init_node(tmp->name), sizeof(t_node));
		else
			ft_lstpushback(node, init_node(tmp->name), sizeof(t_node));
		tmp = tmp->next;
	}
	(*map)->node = (*node);
}

static void	set_tab(t_list **tab, t_map **map)
{
	t_room	*tmp;
	int		left;

	tmp = (*map)->top;
	left = -1;
	while (tmp)
	{
		if (tmp == (*map)->start)
			left = 0;
		if ((*tab) == NULL)
			(*tab) = ft_lstnew(init_tab(tmp->name, left), sizeof(t_tab));
		else
			ft_lstpushback(tab, init_tab(tmp->name, left), sizeof(t_tab));
		tmp = tmp->next;
		left = -1;
	}
	(*map)->tab = (*tab);
}

int			find_path(t_map **map)
{
	t_list	*tab;
	t_list	*node;

	tab = NULL;
	node = NULL;
	set_tab(&tab, map);
	set_node(&node, map);
	path_finding(map);
	if (!check_path(map))
		return (0);
	return (1);
}
