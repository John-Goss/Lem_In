/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jle-quer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/03 19:10:23 by jle-quer          #+#    #+#             */
/*   Updated: 2016/05/31 14:40:30 by jle-quer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

# include <libft.h>
# include <errno.h>

typedef struct		s_tab
{
	char			*name;
	int				left;
	int				passed;
}					t_tab;

typedef struct		s_node
{
	char			*name;
	char			*prev;
}					t_node;

typedef struct		s_room
{
	int				ant;
	char			*name;
	int				x;
	int				y;
	int				to_end;
	int				nbr_neigh;
	t_list			*neighbor;
	struct s_room	*next;
}					t_room;

typedef struct		s_map
{
	struct s_room	*start;
	struct s_room	*end;
	struct s_room	*top;
	struct s_list	*tab;
	struct s_list	*node;
	int				ants;
	int				rooms;
}					t_map;

void		ft_error(char *str);
void		ft_parse(t_map **map);
t_map		*init_map(void);
void		free_array(char **array);
int			get_room_link(t_map **map, char *line);
int			find_path(t_map **map);
int			path_finding(t_map **map);
int			check_neighbors(t_room *room, char *name);
void		check_double_and_pos(t_room *room, t_room *begin);
void		chained_list_set(t_room **room, t_map **map);
t_room		*init_room(void);
t_tab		*init_tab(char *name, int left);
t_node		*init_node(char *name);

#endif
