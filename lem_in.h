/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jle-quer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/03 19:10:23 by jle-quer          #+#    #+#             */
/*   Updated: 2016/06/09 16:32:18 by jle-quer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

# include "libft.h"
# include <errno.h>

# define RED "\x1b[31m"
# define GREEN "\033[32m"
# define YELLOW "\033[1;33m"
# define BLUE "\033[1;34m"
# define RST "\x1b[0m"

typedef struct		s_tab
{
	char			*name;
	int				left;
	int				passed;
}					t_tab;

typedef struct		s_final
{
	char			*name;
	int				ant;
}					t_final;

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
	struct s_room	*prev;
}					t_room;

typedef struct		s_map
{
	struct s_room	*start;
	struct s_room	*end;
	struct s_room	*top;
	struct s_list	*tab;
	struct s_list	*node;
	struct s_list	*path;
	struct s_list	*path_start;
	struct s_list	*path_end;
	struct s_list	*line;
	int				ants;
	int				rooms;
}					t_map;

int	g_op_count;
int	g_opt_v;
int	g_opt_c;
int	g_opt_h;

void				ft_error(char *str);
void				ft_parse(t_map **map);
t_map				*init_map(void);
void				free_array(char **array);
void				display_help(void);
int					parse_opt(int ac, char **argv);
int					get_room_link(t_map **map, char *line);
int					find_path(t_map **map);
int					path_finding(t_map **map);
int					check_neighbors(t_room *room, char *name);
int					end_passed(char *end_name, t_list *tab);
void				set_moves(t_map **map);
void				check_double_and_pos(t_room *room, t_room *begin);
void				chained_list_set(t_room **room, t_map **map);
void				display_map(t_list *line);
void				get_line(t_map **map, char *line);
void				del_last_line(t_list *line);
int					check_path(t_map **map);
int					nbr_of_node(t_list *node);
t_room				*init_room(void);
t_room				*set_first_on_ptr(t_room *first, char *array);
t_room				*set_second_on_ptr(t_room *second, char *array);
t_tab				*init_tab(char *name, int left);
t_node				*init_node(char *name);
t_final				*init_final(char *name);

#endif
