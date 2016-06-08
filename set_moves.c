/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_moves.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jle-quer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/07 14:44:57 by jle-quer          #+#    #+#             */
/*   Updated: 2016/06/08 17:50:20 by jle-quer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void	set_rooms_neighbors(t_map **map)
{
	t_list	*list;
	t_list	*m_path;

	list = NULL;
	m_path = (*map)->path;
	while (m_path)
	{
		ft_lstpushfront(&list, init_final(m_path->content), sizeof(t_final));
		m_path = m_path->next;
	}
	free((*map)->path);
	(*map)->path = list;
	(*map)->path_end = list;
	m_path = (*map)->path;
	while (m_path->next)
		m_path = m_path->next;
	(*map)->path_start = m_path;
}

static void	moves_ope(t_map **map)
{
	t_list	*ptr;
	t_list	*prev;

	ptr = (*map)->path;
	while (ptr->next)
	{
		prev = ptr->next;
		if ((ptr == (*map)->path_end || ((t_final *)ptr->content)->ant == 0) &&
				((t_final *)prev->content)->ant > 0)
		{
			ft_printf("L%d-%s ", ((t_final *)prev->content)->ant,
					((t_final *)ptr->content)->name);
			((t_final *)ptr->content)->ant = ((t_final *)prev->content)->ant;
			((t_final *)prev->content)->ant = 0;
		}
		ptr = ptr->next;
	}
}

void		set_moves(t_map **map)
{
	int	nbr;

	nbr = 1;
	set_rooms_neighbors(map);
	((t_final *)(*map)->path_start->content)->ant = (*map)->ants;
	while (((t_final *)(*map)->path_end->content)->ant != (*map)->ants)
	{
		if (nbr <= (*map)->ants)
			((t_final *)(*map)->path_start->content)->ant = nbr;
		moves_ope(map);
		if (((t_final *)(*map)->path_end->content)->ant != (*map)->ants)
			ft_putchar('\n');
		nbr++;
	}
	ft_putchar('\n');
}
