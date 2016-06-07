/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jle-quer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/31 13:10:56 by jle-quer          #+#    #+#             */
/*   Updated: 2016/06/07 13:09:33 by jle-quer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_node	*init_node(char *name)
{
	t_node	*new;

	new = NULL;
	if (!(new = (t_node *)malloc(sizeof(t_node))))
		return (NULL);
	new->name = ft_strdup(name);
	new->prev = NULL;
	return (new);
}

void	get_line(t_map **map, char *line)
{
	t_list	*list;
	char	*tmp;

	list = NULL;
	tmp = ft_strdup(line);
	if ((*map)->line != NULL)
		ft_lstpushback(&(*map)->line, tmp, ft_strlen(tmp));
	else
	{
		list = ft_lstnew(tmp, ft_strlen(tmp));
		(*map)->line = list;
	}
}

void	display_map(t_list *line)
{
	while (line)
	{
		ft_printf("%s\n", line->content);
		line = line->next;
	}
}
