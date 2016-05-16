/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jle-quer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/03 19:09:40 by jle-quer          #+#    #+#             */
/*   Updated: 2016/05/16 18:29:19 by jle-quer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int main(void)
{
	t_map	map;
	t_room	*ptr;
	int		i = 0;

	ft_parse(&map);
	ptr = map.top;
	while (ptr)
	{
		if (!i)
			ft_printf("Nom Map Start : %s\n\n", map.start->name);
		else
		{
			ft_printf("Nom Room : %s\n", ptr->name);
			ptr = ptr->next;
		}
		i = 1;
	}
	ft_printf("\nNom Map End : %s\n", map.end->name);
	ft_printf("\nNbr Voisin Room %s : %d -> Name is : %s\n", map.top->name, map.top->neighbor->nbr_neigh, map.top->neighbor->name);
	ft_printf("\nNbr Voisin Room %s", map.start->neighbor->name);
	return (0);
}
