/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jle-quer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/03 19:10:23 by jle-quer          #+#    #+#             */
/*   Updated: 2016/05/26 17:19:20 by jle-quer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

# include <libft.h>
# include <errno.h>

typedef struct			s_neighbors
{
	char				*name;
	struct s_neighbors	*next;
}						t_neighbors;

typedef struct		s_room
{
	int				ant;
	char			*name;
	int				x;
	int				y;
	int				to_end;
	int				nbr_neigh;
	t_neighbors		*neighbor;
	struct s_room	*next;
}					t_room;

typedef struct		s_map
{
	struct s_room	*start;
	struct s_room	*end;
	struct s_room	*top;
	int				ants;
	int				rooms;
}					t_map;

void		ft_error(char *str);
void		ft_parse(t_map **map);
t_map		*init_map(void);
void		free_array(char **array);
int			get_room_link(t_map **map, char *line);
t_neighbors	*init_neighbors(char *name);
int			check_acquisition(t_map *map);
int			check_neighbors(t_room *room, char *name);
void		check_double_and_pos(t_room *room, t_room *begin);
void		chained_list_set(t_room **room, t_map **map);
t_room		*init_room(void);

#endif
