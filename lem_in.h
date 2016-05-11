/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jle-quer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/03 19:10:23 by jle-quer          #+#    #+#             */
/*   Updated: 2016/05/10 17:48:10 by jle-quer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

# include "libft.h"
# include <errno.h>

typedef struct		s_room
{
	int				ant;
	char			*name;
	int				x;
	int				y;
	struct s_room	*next;
	struct s_room	*prev;
}					t_room;

typedef struct		s_map
{
	t_room			*start;
	t_room			*end;
	int				ants;
}					t_map;

void	ft_error(char *str);
t_map	ft_parse(void);

#endif
