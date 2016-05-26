/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jle-quer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/04 18:09:25 by jle-quer          #+#    #+#             */
/*   Updated: 2016/05/26 14:31:11 by jle-quer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include <get_next_line.h>

static void		get_ants(t_map **map)
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
			(*map)->ants = ft_atoi(line);
			if ((*map)->ants == 0)
				ft_error("ERROR - NO ANTS");
			break ;
		}
		else
			ft_error("ERROR");
	}
	free(line);
}

static int		parse_room(t_room **room, t_map **map, char *line, int type)
{
	char	**array;
	int		i;

	i = 0;
	array = ft_strsplit(line, ' ');
	while (array[i])
		i++;
	if (i != 3 || !ft_isint(array[1]) || !ft_isint(array[2]))
		return (0);
	(*room)->name = ft_strdup(array[0]);
	(*room)->x = ft_atoi(array[1]);
	(*room)->y = ft_atoi(array[2]);
	(*map)->rooms++;
	if (type == 0)
	{
		(*room)->ant = (*map)->ants;
		(*map)->start = *room;
	}
	else if (type == 1)
		(*map)->end = *room;
	chained_list_set(room, map);
	free_array(array);
	return (1);
}

static int		is_room(t_map **map, char *line)
{
	t_room		*new;
	int			i;
	static int	start_end[2] = {0, 0};

	i = 0;
	new = init_room();
	(start_end[0] == 1 && ft_strcmp(line, "##start") == 0) || (start_end[1] == 1
			&& ft_strcmp(line, "##end") == 0) ? ft_error("ERROR") : 0;
	if (ft_strcmp(line, "##start") == 0)
	{
		start_end[0] = 1;
		get_next_line(0, &line);
		i = parse_room(&new, map, line, 0);
	}
	else if (ft_strcmp(line, "##end") == 0)
	{
		start_end[1] = 1;
		get_next_line(0, &line);
		i = parse_room(&new, map, line, 1);
	}
	else
		i = parse_room(&new, map, line, 42);
	if (i == 0)
		return (0);
	return (1);
}

static void		get_rooms(t_map **map)
{
	char		*line;
	int			i;

	i = 0;
	line = NULL;
	while (get_next_line(0, &line) == 1)
	{
		if (ft_strcmp(line, "##start") != 0 && ft_strcmp(line, "##end") != 0 &&
				line[0] == '#' && line[1] == '#')
			continue ;
		if (i == 0 && is_room(map, line) == 1)
			continue ;
		if (line[0] == '#' && line[1] != '#')
			continue ;
		if (get_room_link(map, line) == 1)
		{
			i = 1;
			continue ;
		}
		break ;
	}
	free(line);
}

void			ft_parse(t_map *map)
{
	init_map(&map);
	get_ants(&map);
	get_rooms(&map);
}
