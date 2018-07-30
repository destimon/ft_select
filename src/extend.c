/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extend.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcherend <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/29 21:14:39 by dcherend          #+#    #+#             */
/*   Updated: 2018/07/29 21:15:57 by dcherend         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_select.h"

int			erase_begin(t_elem **el)
{
	t_elem	*cur;

	if ((*el)->is_curr == true)
	{
		cur = (*el)->next;
		free((*el)->path);
		free((*el));
		(*el) = cur;
		(*el)->is_curr = true;
		return (1);
	}
	return (0);
}

void		cursor_handler(_Bool is_curr, int *curs)
{
	if (is_curr == true)
	{
		ft_putstr_fd("-> ", 0);
		(*curs) = 3;
	}
}

void		print_border_fence(int limit)
{
	int		i;

	i = 0;
	while (i < limit)
	{
		ft_putstr_fd("=", 0);
		i++;
	}
}