/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_opt.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jle-quer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/09 14:56:58 by jle-quer          #+#    #+#             */
/*   Updated: 2016/06/09 16:14:44 by jle-quer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static int	set_opt(char *av)
{
	int	i;

	i = 0;
	if (!av[i])
		return (-1);
	while (av[i])
	{
		if (ft_isdigit(av[i]) == 1)
			return (-1);
		else if (av[i] == 'v' && g_opt_v == 0)
			g_opt_v += 1;
		else if (av[i] == 'c' && g_opt_c == 0)
			g_opt_c += 1;
		else if (av[i] == 'o' && g_op_count == 0)
			g_op_count += 1;
		else if (av[i] == 'h' && g_opt_h == 0)
			g_opt_h += 1;
		else
			return (-1);
		i++;
	}
	if (g_opt_v > 1 || g_opt_c > 1 || g_op_count > 1 || g_opt_h > 1)
		ft_error("ERROR ON OPTIONS");
	return (1);
}

int			parse_opt(int ac, char **argv)
{
	int		i;

	i = 1;
	g_op_count = 0;
	while (i < ac)
	{
		if (argv[i][0] == '-' && argv[i][1] != '-')
		{
			if (set_opt(argv[i] + 1) == -1)
				ft_error("ERROR ON OPTIONS");
			else if (set_opt(argv[i] + 1) == 0)
				break ;
		}
		else if (argv[i][0] == '-' && argv[i][1] == '-' && !argv[i][2])
		{
			if (argv[i + 1])
				ft_error("ERROR ON OPTIONS");
			break ;
		}
		else
			ft_error("ERROR ON OPTIONS");
		i++;
	}
	return (0);
}
