/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jle-quer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/03 19:09:40 by jle-quer          #+#    #+#             */
/*   Updated: 2016/05/20 14:28:22 by jle-quer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int	main(void)
{
	t_map	map;

	ft_parse(&map);
//	if (!check_acquisition(&map))
//		ft_error("ERROR");
	while (map.top)
	{
		ft_printf("Nom Room : %s -- ", map.top->name);
		while (map.top->neighbor)
		{
			ft_printf("Nom Voisins : %s", map.top->neighbor->name);
			map.top->neighbor = map.top->neighbor->next;
		}
		map.top = map.top->next;
		ft_putchar('\n');
	}
	return (0);
}
