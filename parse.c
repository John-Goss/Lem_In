/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jle-quer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/04 18:09:25 by jle-quer          #+#    #+#             */
/*   Updated: 2016/05/10 13:15:37 by jle-quer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include <fcntl.h>

void	ft_parse(char **av)
{
	char	*line;
	int		fd;

	(void)av[0];
	line = NULL;
	fd = open("./test.map", O_RDONLY);
	while (get_next_line(fd, &line) == 1)
		ft_printf("%s", line);
}
