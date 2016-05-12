/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jle-quer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/04 18:09:25 by jle-quer          #+#    #+#             */
/*   Updated: 2016/05/12 20:39:52 by jle-quer         ###   ########.fr       */
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

static int	is_room(t_map *map, char *line)
{
	t_room		new;
	static int	start_end[2] = {0, 0};

	new = (t_room){0, NULL, 0, 0, 0, NULL, NULL};
	(start_end[0] == 1 && ft_strcmp(line, "##start") == 0) ||
		(start_end[1] == 1 && ft_strcmp(line, "##end") == 0) ? ft_error("ERROR") : 0;
	if (ft_strcmp(line, "##start") == 0)
	{
		start_end[0] = 1;
		get_next_line(0, &line);
		is_start_end(&new, map, line, 0);
	}
	else if (ft_strcmp(line, "##end") == 0)
	{
		start_end[1] = 1;
		get_next_line(0, &line);
		is_start_end(&new, map, line, 1);
	}
	else
		return (0);
//		parse_room(&new, map, line);
	return (1);
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
		if (is_room(map, line) == 1)
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
