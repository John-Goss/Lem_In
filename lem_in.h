/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jle-quer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/03 19:10:23 by jle-quer          #+#    #+#             */
/*   Updated: 2016/05/15 19:19:32 by jle-quer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

# include <libft.h>
# include <errno.h>

typedef struct		s_room
{
	int				ant;
	char			*name;
	int				x;
	int				y;
	int				to_end;
	struct s_room	*top;
	struct s_room	*next;
	struct s_room	*prev;
}					t_room;

typedef struct		s_map
{
	struct s_room	*start;
	struct s_room	*end;
	int				ants;
	int				rooms;
}					t_map;

int	g_first;

void	ft_error(char *str);
void	ft_parse(t_map *map);
void	parse_room(t_room *room, t_map *map, char *line, int type);
void	init_map(t_map *map);

#endif
