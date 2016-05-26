/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jle-quer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/03 19:09:40 by jle-quer          #+#    #+#             */
/*   Updated: 2016/05/26 12:19:52 by jle-quer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int	main(void)
{
	t_map	map;

	ft_parse(&map);
//	if (!check_acquisition(&map))
//		ft_error("ERROR");
	ft_printf("Addrs 2 : [%p]\n", map.top);
	while (map.top)
	{
		ft_printf("Nom Room : %s -- Nombre Voisins : %d\n", map.top->name, map.top->nbr_neigh);
		while (map.top->neighbor)
		{
			ft_printf("ROOM : %s ", map.top->neighbor->name);
			map.top->neighbor = map.top->neighbor->next;
		}
		ft_putchar('\n');
		map.top = map.top->next;
		ft_putchar('\n');
	}
	return (0);
}
