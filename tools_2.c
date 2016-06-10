/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jle-quer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/31 13:10:56 by jle-quer          #+#    #+#             */
/*   Updated: 2016/06/10 12:14:16 by jle-quer         ###   ########.fr       */
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

t_final	*init_final(char *name)
{
	t_final	*new;

	new = NULL;
	if (!(new = (t_final *)malloc(sizeof(t_final))))
		return (NULL);
	new->name = ft_strdup(name);
	new->ant = 0;
	return (new);
}

void	del_last_line(t_list *line)
{
	t_list	*tmp;

	tmp = line;
	while (tmp && tmp->next && tmp->next->next)
		tmp = tmp->next;
	free(tmp->next);
	tmp->next = NULL;
}

void	get_line(t_map **map, char *line)
{
	t_list	*list;
	char	*tmp;

	list = NULL;
	if (*line == '\n' || *line == '\0' || *line == '\t')
		return ;
	tmp = ft_strdup(line);
	if ((*map)->line != NULL)
		ft_lstpushback(&(*map)->line, tmp, ft_strlen(tmp) + 1);
	else
	{
		list = ft_lstnew(tmp, ft_strlen(tmp) + 1);
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
	ft_putchar('\n');
}
