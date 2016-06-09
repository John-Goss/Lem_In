/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jle-quer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/06 17:07:54 by jle-quer          #+#    #+#             */
/*   Updated: 2016/06/09 11:51:33 by jle-quer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static int	pushfront_path(t_list **node, t_list **path, t_map **map)
{
	while (ft_strcmp(((t_node *)(*node)->content)->name, (*map)->end->name)
			!= 0)
		(*node) = (*node)->next;
	ft_lstpushfront(path, (*map)->end->name, sizeof((*map)->end->name));
	return (1);
}

static void	parse_path(t_map **map)
{
	t_list	*node;
	t_list	*path;
	char	*ptr;
	int		first;
	int		i;

	i = 1;
	ptr = NULL;
	path = NULL;
	first = (nbr_of_node((*map)->node)) + 1;
	while (--first != 0 && (node = (*map)->node))
	{
		if (i && (pushfront_path(&node, &path, map) == 1))
			i = 0;
		else
		{
			while (ft_strcmp(((t_node *)node->content)->name, ptr) != 0)
				node = node->next;
			ft_lstpushfront(&path, ptr, sizeof(ptr));
		}
		if (((t_node *)node->content)->prev == NULL)
			break ;
		ptr = ft_strdup(((t_node *)node->content)->prev);
	}
	(*map)->path = path;
}

int			check_path(t_map **map)
{
	t_list	*tmp;

	parse_path(map);
	tmp = (*map)->path;
	if (!tmp)
		return (0);
	while (tmp->next)
		tmp = tmp->next;
	if (ft_strcmp((*map)->path->content, (*map)->start->name) != 0 ||
			ft_strcmp(tmp->content, (*map)->end->name) != 0)
		return (0);
	return (1);
}
