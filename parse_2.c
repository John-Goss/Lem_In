/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jle-quer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/12 12:47:35 by jle-quer          #+#    #+#             */
/*   Updated: 2016/06/09 12:31:58 by jle-quer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static int	check_exist_room(char *first, char *last, t_room *top)
{
	t_room	*ptr;
	int		i;
	int		j;

	i = 0;
	j = 0;
	ptr = top;
	if (ft_strcmp(first, last) == 0)
		ft_error("ERROR");
	while (ptr)
	{
		if (ft_strcmp(first, ptr->name) == 0)
			i++;
		if (ft_strcmp(last, ptr->name) == 0)
			j++;
		if (i == 1 && j == 1)
			return (1);
		ptr = ptr->next;
	}
	ft_error("ERROR");
	return (0);
}

static void	set_2nd_room_neighbor(t_room **top, char **array)
{
	t_list	*new;
	t_room	*tmp;

	tmp = *top;
	new = NULL;
	while (ft_strcmp(tmp->name, array[1]) != 0 && tmp)
		tmp = tmp->next;
	if (!check_neighbors(tmp, array[0]))
		return ;
	if (tmp->neighbor)
		ft_lstpushback(&(tmp->neighbor), array[0], sizeof(array[0]));
	else
	{
		new = ft_lstnew(array[0], sizeof(array[0]));
		tmp->neighbor = new;
	}
	tmp->nbr_neigh++;
}

static void	set_room_link(t_room **top, char **array,
		t_room *first, t_room *second)
{
	t_list		*new;

	first = *top;
	second = *top;
	new = NULL;
	first = set_first_on_ptr(first, array[0]);
	second = set_second_on_ptr(second, array[1]);
	if (!check_neighbors(first, array[1]))
		return ;
	if (ft_strcmp(first->name, array[0]) == 0 &&
			ft_strcmp(second->name, array[1]) == 0)
	{
		if (first->neighbor)
			ft_lstpushback(&(first->neighbor), array[1], sizeof(array[1]));
		else
		{
			new = ft_lstnew(array[1], sizeof(array[1]));
			first->neighbor = new;
		}
		first->nbr_neigh++;
		set_2nd_room_neighbor(top, array);
	}
	else
		ft_error("ERROR");
}

void		chained_list_set(t_room **room, t_map **map)
{
	t_room	*ptr;

	ptr = NULL;
	if ((*map)->rooms == 1)
	{
		(*room)->next = NULL;
		(*map)->top = *room;
	}
	else
	{
		ptr = (*map)->top;
		while (ptr->next)
			ptr = ptr->next;
		ptr->next = *room;
		(*room)->next = NULL;
	}
	check_double_and_pos(*room, (*map)->top);
}

int			get_room_link(t_map **map, char *line)
{
	int			i;
	t_room		*first;
	t_room		*second;
	char		**array;

	i = 0;
	first = NULL;
	second = NULL;
	array = ft_strsplit(line, '-');
	while (array[i])
		i++;
	if (i != 2 || !check_exist_room(array[0], array[1], (*map)->top))
		return (0);
	set_room_link(&(*map)->top, array, first, second);
	return (1);
}
