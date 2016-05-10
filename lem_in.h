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

# include "./Libft/INCLUDES/libft.h"
# include <errno.h>
# include <stdio.h>

void	ft_error(char *str);
void	ft_parse();
int		get_next_line(int const fd, char **line);

#endif
