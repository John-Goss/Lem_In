/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jle-quer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/04 18:09:25 by jle-quer          #+#    #+#             */
/*   Updated: 2016/05/15 19:26:06 by jle-quer         ###   ########.fr       */
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
	new->top = NULL;
	new->next = NULL;
	new->prev = NULL;
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
}

static int		is_room(t_map *map, char *line)
{
	t_room		*new;
	static int	start_end[2] = {0, 0};

	new = init_room();
	(start_end[0] == 1 && ft_strcmp(line, "##start") == 0) ||
		(start_end[1] == 1 && ft_strcmp(line, "##end") == 0) ? ft_error("ERROR") : 0;
	if (ft_strcmp(line, "##start") == 0)
	{
		start_end[0] = 1;
		get_next_line(0, &line);
		parse_room(new, map, line, 0);
	}
	if (ft_strcmp(line, "##end") == 0)
	{
		start_end[1] = 1;
		get_next_line(0, &line);
		parse_room(new, map, line, 1);
	}
	else
		parse_room(new, map, line, 42);
	g_first = 1;
	return (1);
}

static void	get_rooms(t_map *map)
{
	char		*line;
	int			i;

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

void		ft_parse(t_map *map)
{
	init_map(map);
	get_ants(map);
	get_rooms(map);
}
