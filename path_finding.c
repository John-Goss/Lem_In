/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_finding.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jle-quer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/31 14:34:05 by jle-quer          #+#    #+#             */
/*   Updated: 2016/06/03 16:22:03 by jle-quer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

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
			if (ft_strcmp(ptr->name, ((t_tab *)tmp->content)->name) == 0 && ((t_tab *)tmp->content)->passed == 0)
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

	ret = NULL;
	ptr = tab;
	nbr = 0;
	while (ptr)
	{
		passed = ((t_tab *)ptr->content)->passed;
		nbr = ((t_tab *)ptr->content)->left;
		if (passed == 0 && nbr >= 0)
		{
			if (ptr->next && ((t_tab *)ptr->next->content)->left != -1 &&
					nbr > ((t_tab *)ptr->next->content)->left &&
					((t_tab *)ptr->next->content)->passed == 0)
				ret = ptr->next;
			ret = ptr;
		}
		ptr = ptr->next;
	}
	if (!ret)
		return (NULL);
	return (ret);
}

static int		set_node_prev(char *prev, char *name, t_list *node)
{
	t_list	*ptr;

	ptr = node;
	while (ptr)
	{
		if (ft_strcmp(prev, ((t_node *)ptr->content)->name) == 0)
		{
			((t_node *)ptr->content)->prev = ft_strdup(name);
			return (1);
		}
		ptr = ptr->next;
	}
	return (0);
}

static int		set_tab_neighbor(char *name, int left, t_list *tab)
{
	t_list	*ptr;

	ptr = tab;
	while (ptr)
	{
		if (ft_strcmp(name, ((t_tab *)ptr->content)->name) == 0)
		{
			if (((t_tab *)ptr->content)->left > left
				|| ((t_tab *)ptr->content)->left == -1)
			{
				((t_tab *)ptr->content)->left = left;
				return (1);
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
	while (tab_start)
	{
		if (!(neighbor = find_neighbor(tab_start, (*map)->top, (*map)->tab)))
			return (0);
		((t_tab *)tab_start->content)->passed = 1;
		while (neighbor)
		{
//			meme nom que voisin dans tab = left = tab_start value + 1;
			if (!(set_tab_neighbor((char *)neighbor->content,
				((int)((t_tab *)tab_start->content)->left) + 1, (*map)->tab)))
				//return (0);
				break ;
//			meme nom que voisim dans node = prev = tab_start name;
			if (!(set_node_prev((char *)neighbor->content,
				((char *)((t_tab *)tab_start->content)->name), (*map)->node)))
				//return (0);
				break ;
			neighbor = neighbor->next;
		}
		tab_start = find_start((*map)->tab);
	}
	return (1);
}
