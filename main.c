/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jle-quer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/03 19:09:40 by jle-quer          #+#    #+#             */
/*   Updated: 2016/05/15 19:26:08 by jle-quer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int main(void)
{
	t_map	map;
	t_room	*ptr;
	int		i = 0;

	ft_parse(&map);
	ptr = map.start;
	while (ptr)
	{
		if (!i)
			ft_printf("Nom Map Start : %s\nCoord X : %d, Coord Y : %d\n\n", map.start->name, map.start->x, map.start->y);
		else
			ft_printf("Nom Room : %s\nCoord X : %d, Coord Y : %d\n\n", ptr->name, ptr->x, ptr->y);
		i = 1;
		ptr = ptr->next;
	}
	ft_printf("Nom Map End : %s\nCoord X : %d, Coord Y : %d\n", map.end->name, map.end->x, map.end->y);
	return (0);
}
