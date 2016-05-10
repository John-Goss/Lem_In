/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jle-quer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/04 18:09:25 by jle-quer          #+#    #+#             */
/*   Updated: 2016/05/10 18:45:55 by jle-quer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static int	get_struct(char *line)
{
	t_map	*new;

	return (new);
}

void		ft_parse(void)
{
	t_map	map;
	char	*line;
	int		error;

	line = NULL;
	error = 0;
	while (get_next_line(0, &line) == 1)
		if ((map = get_struct(line, &map)) == NULL)
			error = 1;
	if (error == 0)
	{
		line = NULL;
		while (get_next_line(0, &line) == 1)
			ft_putendl(line);
		ft_putchar('\n');
	}
	else if (error == 1)
		ft_error("ERROR");
}
