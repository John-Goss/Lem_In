/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_finding.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jle-quer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/31 14:34:05 by jle-quer          #+#    #+#             */
/*   Updated: 2016/06/07 11:36:44 by jle-quer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static int		end_passed(char *end_name, t_list *tab)
{
	t_list	*ptr;

	ptr = tab;
	while (ptr)
	{
		if (ft_strcmp(end_name, ((t_tab *)ptr->content)->name) == 0)
		{
			if (((t_tab *)ptr->content)->passed == 1)
				return (1);
		}
		ptr = ptr->next;
	}
	return (0);
}

static t_list	*find_neighbor(t_list *room, t_room *top, t_list *tab)
{
	t_list	*ret;
	t_list	*tmp;
	t_room	*ptr;

	ret = NULL;
	ptr = top;
	while (ptr)
	{
		if (ft_strcmp(ptr->name, ((t_tab *)room->content)->name) == 0)
		{
			tmp = tab;
			while (ft_strcmp(ptr->name, ((t_tab *)tmp->content)->name) != 0)
				tmp = tmp->next;
			if (ft_strcmp(ptr->name, ((t_tab *)tmp->content)->name) == 0 &&
					((t_tab *)tmp->content)->passed == 0)
			{
				ret = ptr->neighbor;
				return (ret);
			}
		}
		ptr = ptr->next;
	}
	return (NULL);
}

static t_list	*find_start(t_list *tab)
{
	t_list	*ptr;
	t_list	*ret;
	int		nbr;
	int		passed;

	ptr = tab;
	ret = NULL;
	nbr = 0;
	while (ptr)
	{
		passed = ((t_tab *)ptr->content)->passed;
		nbr = ((t_tab *)ptr->content)->left;
		if (nbr == -1 || passed == 1)
		{
			ptr = ptr->next;
			continue ;
		}
		if (!ret)
			ret = ptr;
		else
			if (nbr < ((t_tab *)ret->content)->left)
				ret = ptr;
		ptr = ptr->next;
	}
	if (!ret)
		return (NULL);
	return (ret);
}

static int		set_node_prev(char *room, char *prev, t_list *node)
{
	t_list	*ptr;

	ptr = node;
	while (ptr)
	{
		if (ft_strcmp(room, ((t_node *)ptr->content)->name) == 0)
		{
			((t_node *)ptr->content)->prev = ft_strdup(prev);
			return (1);
		}
		ptr = ptr->next;
	}
	return (0);
}

static int		set_tab_neighbor(char *neigh_name, int new_left, t_list *tab)
{
	t_list	*ptr;

	ptr = tab;
	while (ptr)
	{
		if (ft_strcmp(neigh_name, ((t_tab *)ptr->content)->name) == 0)
		{
			if (((t_tab *)ptr->content)->passed == 0)
			{
				if (((t_tab *)ptr->content)->left > new_left
					|| ((t_tab *)ptr->content)->left == -1)
				{
					((t_tab *)ptr->content)->left = new_left;
					return (1);
				}
			}
		}
		ptr = ptr->next;
	}
	return (0);
}

int				path_finding(t_map **map)
{
	t_list	*tab_start;
	t_list	*neighbor;

	neighbor = NULL;
	tab_start = find_start((*map)->tab);
	while (tab_start && !end_passed((*map)->end->name, (*map)->tab))
	{
		neighbor = find_neighbor(tab_start, (*map)->top, (*map)->tab);
		while (neighbor)
		{
			if (!(set_tab_neighbor((char *)neighbor->content,
				(((t_tab *)tab_start->content)->left + 1), (*map)->tab)))
			{
				neighbor = neighbor->next;
				continue;
			}
			set_node_prev((char *)neighbor->content,
				((t_tab *)tab_start->content)->name, (*map)->node);
			neighbor = neighbor->next;
		}
		((t_tab *)tab_start->content)->passed = 1;
		tab_start = find_start((*map)->tab);
	}
	return (1);
}
