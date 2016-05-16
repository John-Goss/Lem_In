/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jle-quer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/04 18:09:25 by jle-quer          #+#    #+#             */
/*   Updated: 2016/05/16 16:30:03 by jle-quer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include <get_next_line.h>

static t_room	*init_room(void)
{
	t_room	*new;

	new = NULL;
	if (!(new = (t_room *)malloc(sizeof(t_room))))
		return (NULL);
	new->ant = 0;
	new->name = NULL;
	new->x = 0;
	new->y = 0;
	new->to_end = 0;
	new->neighbor = NULL;
	new->next = NULL;
	return (new);
}

static void		get_ants(t_map *map)
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
	free(line);
}

static int		is_room(t_map *map, char *line)
{
	t_room		*new;
	int			i;
	static int	start_end[2] = {0, 0};

	i = 0;
	new = init_room();
	(start_end[0] == 1 && ft_strcmp(line, "##start") == 0) ||
		(start_end[1] == 1 && ft_strcmp(line, "##end") == 0) ? ft_error("ERROR") : 0;
	if (ft_strcmp(line, "##start") == 0)
	{
		start_end[0] = 1;
		get_next_line(0, &line);
		i = parse_room(new, map, line, 0);
	}
	else if (ft_strcmp(line, "##end") == 0)
	{
		start_end[1] = 1;
		get_next_line(0, &line);
		i = parse_room(new, map, line, 1);
	}
	else
		i = parse_room(new, map, line, 42);
	return i == 0 ? (0) : (1);
}

static int		get_rooms(t_map *map)
{
	char		*line;
	int			i;

	i = 0;
	line = NULL;
	while (get_next_line(0, &line) == 1)
	{
		if (i == 0 && is_room(map, line) == 1)
			continue ;
		if (line[0] == '#' && line[1] != '#')
			continue ;
		if (get_room_link(map, line) == 1)
		{
			i = 1;
			continue ;
		}
		else
			ft_error("ERROR");
	}
	free(line);
	return (1);
}

void		ft_parse(t_map *map)
{
	init_map(map);
	get_ants(map);
	get_rooms(map);
}
