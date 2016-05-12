/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jle-quer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/04 18:09:25 by jle-quer          #+#    #+#             */
/*   Updated: 2016/05/12 17:01:37 by jle-quer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include <get_next_line.h>

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
			if (map->ants == 0)
				ft_error("ERROR - NO ANTS");
			break ;
		}
		else
			ft_error("ERROR");
	}
}

static char	*is_room(t_map *map, char *line)
{
	t_room	new;

	new = (t_room){0, NULL, 0, 0, 0, NULL, NULL};
	(map->start && ft_strcmp(line, "##start"))
		|| (map->end && ft_strcmp(line, "##end")) == 0 ? ft_error("ERROR") : 0;
	if (ft_strcmp(line, "##start") == 0)
	{
		get_next_line(0, &line);
		line = is_start(&new, map, line);
	}
//	else if (ft_strcmp(line, "##end") == 0)
//		line = is_end(&new, map, get_next_line(0, &line));
//	else
//		parse_room(&new, map, line);
	return (line);
}

static void	get_rooms(t_map *map)
{
	char	*line;
	int		i;

	i = 0;
	line = NULL;
	while (get_next_line(0, &line) == 1)
	{
		if (line[0] == '#' && line[1] != '#')
			continue ;
		if ((line = is_room(map, line)))
			continue ;
		else
			ft_error("ERROR");
	}
}

t_map		ft_parse(void)
{
	t_map	map;

	map = (t_map){NULL, NULL, 0, 0};
	get_ants(&map);
	get_rooms(&map);
	return (map);
}
