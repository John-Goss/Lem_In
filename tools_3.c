/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jle-quer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/09 11:35:26 by jle-quer          #+#    #+#             */
/*   Updated: 2016/06/09 17:00:07 by jle-quer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		nbr_of_node(t_list *node)
{
	t_list	*tmp;
	int		i;

	i = 0;
	tmp = node;
	while (tmp)
	{
		i++;
		tmp = tmp->next;
	}
	return (i);
}

int		end_passed(char *end_name, t_list *tab)
{
	t_list	*ptr;

	ptr = tab;
	while (ptr)
	{
		if (ft_strcmp(end_name, ((t_tab *)ptr->content)->name) == 0)
		{
			if (((t_tab *)ptr->content)->passed == 1)
				return (1);
		}
		ptr = ptr->next;
	}
	return (0);
}

t_room	*set_first_on_ptr(t_room *first, char *array)
{
	while (ft_strcmp(first->name, array) != 0 && first)
		first = first->next;
	return (first);
}

t_room	*set_second_on_ptr(t_room *second, char *array)
{
	while (ft_strcmp(second->name, array) != 0 && second)
		second = second->next;
	return (second);
}

void	display_help(void)
{
	if (g_opt_c == 1 && isatty(STDOUT_FILENO))
	{
		ft_putstr(RED);
		ft_putstr("------ HELP VIEW ------\n\n");
		ft_putstr("/// -h ///   See Help View\n");
		ft_putstr("/// -v ///   Verbose Mode Activation\n");
		ft_putstr("/// -c ///   Color Mode Activation\n");
		ft_putstr("/// -o ///   Stroke Count Display\n\n");
		ft_putstr(YELLOW);
		ft_putstr("\nPlease Re-Run Without Help Mode !\n");
		ft_putstr(RST);
	}
	else
	{
		ft_putstr("------ HELP VIEW ------\n\n");
		ft_putstr("/// -h ///   See Help View\n");
		ft_putstr("/// -v ///   Verbose Mode Activation\n");
		ft_putstr("/// -c ///   Color Mode Activation\n");
		ft_putstr("/// -o ///   Stroke Count Display\n\n");
		ft_putstr("\nPlease Re-Run Without Help Mode !\n");
	}
	exit(0);
}
