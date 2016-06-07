/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jle-quer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/03 19:09:40 by jle-quer          #+#    #+#             */
/*   Updated: 2016/06/07 16:52:34 by jle-quer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int	main(void)
{
	t_map	*map;

	map = NULL;
	map = init_map();
	ft_parse(&map);
	if (!map->start || !map->end || !map->start->neighbor ||
			!map->end->neighbor || !find_path(&map))
		ft_error("ERROR");
	display_map(map->line);
	set_moves(&map);
	return (0);
}
