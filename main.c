/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jle-quer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/03 19:09:40 by jle-quer          #+#    #+#             */
/*   Updated: 2016/06/09 17:49:47 by jle-quer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int	main(int ac, char **argv)
{
	t_map	*map;

	map = NULL;
	parse_opt(ac, argv);
	if (g_opt_h == 1)
		display_help();
	map = init_map();
	ft_parse(&map);
	if (!map->start || !map->end || !map->start->neighbor ||
			!map->end->neighbor || !find_path(&map))
		ft_error("ERROR");
	display_map(map->line);
	set_moves(&map);
	return (0);
}
