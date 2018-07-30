/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcherend <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/27 16:42:44 by dcherend          #+#    #+#             */
/*   Updated: 2018/07/29 15:14:40 by dcherend         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_select.h"

static t_elem		*init_elem(const char *file)
{
	struct stat		stats;
	t_elem			*el;

	el = (t_elem*)malloc(sizeof(t_elem));
	if (!el)
		return (NULL);
	el->path = ft_strdup(file);
	el->is_curr = false;
	el->is_sel = false;
	if (lstat(file, &stats) >= 0)
		el->mode = stats.st_mode;
	el->next = NULL;
	return (el);
}

t_elem				*init_list(const char **files)
{
	t_elem			*start;
	t_elem			*el;
	int				i;

	start = init_elem(files[0]);
	start->is_curr = true;
	el = start;
	i = 1;
	while (files[i])
	{
		el->next = init_elem(files[i]);
		el = el->next;
		i++;
	}
	return (start);
}

t_elem				**obtain_list(t_elem *el)
{
	t_elem			**arr;
	t_elem			*tmp;
	int				len;
	int				i;

	i = 0;
	len = count_list(el);
	arr = (t_elem**)malloc(sizeof(t_elem*) * (len + 1));
	if (!arr)
		return (NULL);
	tmp = el;
	while (tmp && i < len)
	{
		arr[i] = tmp;
		i++;
		tmp = tmp->next;
	}
	arr[len] = NULL;
	return (arr);
}