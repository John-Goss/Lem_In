/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jle-quer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/09 11:35:26 by jle-quer          #+#    #+#             */
/*   Updated: 2016/06/09 13:13:08 by jle-quer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		nbr_of_node(t_list *node)
{
	t_list	*tmp;
	int		i;

	i = 0;
	tmp = node;
	while (tmp)
	{
		i++;
		tmp = tmp->next;
	}
	return (i);
}

int		end_passed(char *end_name, t_list *tab)
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

t_room	*set_first_on_ptr(t_room *first, char *array)
{
	while (ft_strcmp(first->name, array) != 0 && first)
		first = first->next;
	return (first);
}

t_room	*set_second_on_ptr(t_room *second, char *array)
{
	while (ft_strcmp(second->name, array) != 0 && second)
		second = second->next;
	return (second);
}
