/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jle-quer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/03 19:09:40 by jle-quer          #+#    #+#             */
/*   Updated: 2016/06/02 14:03:23 by jle-quer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int	main(void)
{
	t_map	*map;

	map = NULL;
	map = init_map();
	ft_parse(&map);
	if (!find_path(&map) || !map->start->neighbor || !map->end->neighbor)
		ft_error("ERROR");




/*
	t_room	*tmp;
	tmp = map->top;
	while (tmp)
	{
		ft_printf("Nom Room : %s -- Nombre Voisins : %d\n", tmp->name, tmp->nbr_neigh);
		while (tmp->neighbor)
		{
			ft_printf("ROOM : %s ", tmp->neighbor->content);
			tmp->neighbor = tmp->neighbor->next;
		}
		ft_putchar('\n');
		tmp = tmp->next;
		ft_putchar('\n');
	}
	ft_putstr("\n\n------\n\n");
	t_list	*ptr;
	t_list	*a;
	ptr = map->tab;
	a = map->node;
	while (ptr)
	{
		ft_printf("Nom Tab : %s -- Left : %d -- Passed : %d\n", ((t_tab *)ptr->content)->name, ((t_tab *)ptr->content)->left, ((t_tab *)ptr->content)->passed);
		ptr = ptr->next;
	}
	while (a)
	{
		ft_printf("\nNom Node : %s -- Left : %s", ((t_node *)a->content)->name, ((t_node *)a->content)->prev);
		a = a->next;
	}
*/	return (0);
}
