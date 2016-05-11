/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jle-quer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/04 18:09:25 by jle-quer          #+#    #+#             */
/*   Updated: 2016/05/10 18:45:55 by jle-quer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void	get_ants(t_map *map)
{
	char	*line;

	line = NULL;
	while (42)
	{
		if (get_next_line(0, &line) != 1)
			ft_error("ERROR");
		if (line[0] == '#' && line[1] != '#')
			continue ;
		if (ft_isint(line))
		{
			map->ants = ft_atoi(line);
			break ;
		}
		else
			ft_error("ERROR");
	}
}

t_map		ft_parse(void)
{
	t_map	map;

	map = (t_map){NULL, NULL, 0};
	get_ants(&map);
	return (map);
}
