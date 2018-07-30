/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcherend <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/29 13:02:21 by dcherend          #+#    #+#             */
/*   Updated: 2018/07/29 15:31:50 by dcherend         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_select.h"

int					longest_name(t_elem *el)
{
	t_elem			*tmp;
	int				len;
	int				longest;

	longest = 0;
	tmp = el;
	while (tmp)
	{
		len = (int)ft_strlen(tmp->path);
		if (longest < len)
			longest = len;
		tmp = tmp->next;
	}
	return (longest);
}

int				count_list(t_elem *el)
{
	t_elem		*tmp;
	int			len;

	len = 0;
	tmp = el;
	while (tmp)
	{
		len++;
		tmp = tmp->next;
	}
	return (len);
}

int				current_position(t_elem **arr)
{
	int			i;

	i = 0;
	while (arr[i])
	{
		if (arr[i]->is_curr == true)
			return (i);
		i++;
	}
	return (i);
}