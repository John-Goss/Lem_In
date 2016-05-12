/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jle-quer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/12 12:47:35 by jle-quer          #+#    #+#             */
/*   Updated: 2016/05/12 13:41:23 by jle-quer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

char	*is_start(t_room *room, t_map *map, char *line)
{
	char	*name;

	(void)room;
	(void)map;
	name = NULL;
	name = ft_strnew(ft_strchr_index(line, ' '));
	name = ft_strncpy(name, line, ft_strchr_index(line, ' '));
	ft_putstr(name);
	return (line);
}
