/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jle-quer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/03 19:10:23 by jle-quer          #+#    #+#             */
/*   Updated: 2016/05/12 20:39:48 by jle-quer         ###   ########.fr       */
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
	struct s_room	*next;
	struct s_room	*prev;
}					t_room;

typedef struct		s_map
{
	t_room			*start;
	t_room			*end;
	int				ants;
	int				rooms;
}					t_map;

void	ft_error(char *str);
t_map	ft_parse(void);
void	is_start_end(t_room *room, t_map *map, char *line, int type);

#endif
