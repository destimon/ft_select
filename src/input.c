/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcherend <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/29 14:40:40 by dcherend          #+#    #+#             */
/*   Updated: 2018/07/29 21:15:25 by dcherend         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_select.h"

void			key_esc(t_elem **arr, t_term *te, t_elem **el)
{
	reset_input_mode();
	exit(0);
}

void			key_return(t_elem **arr, t_term *te, t_elem **el)
{
	int			i;

	i = 0;
	tputs(tgetstr("cl", NULL), 1, &complete);
	reset_input_mode();
	while (arr[i])
	{
		if (arr[i]->is_sel == true)
		{
			ft_putstr_fd(arr[i]->path, 1);
			ft_putstr_fd(" ", 1);
		}
		i++;
	}
	tputs(tgetstr("ve", NULL), 1, &complete);
	exit(0);
}

void			key_space(t_elem **arr, t_term *te, t_elem **el)
{
	if (arr[te->ui_cpos]->is_sel == false)
	{
		arr[te->ui_cpos]->is_sel = true;
		if (arr[te->ui_cpos + 1])
		{
			arr[te->ui_cpos]->is_curr = false;
			te->ui_cpos++;
			arr[te->ui_cpos]->is_curr = true;
		}
		else
		{
			arr[te->ui_cpos]->is_curr = false;
			te->ui_cpos = 0;
			arr[te->ui_cpos]->is_curr = true;
		}
	}
	else
		arr[te->ui_cpos]->is_sel = false;
}

void			key_backspace(t_elem **arr, t_term *te, t_elem **el)
{
	t_elem			*cur;
	t_elem			*prev;

	prev = *el;
	if (!prev->next)
	{
		reset_input_mode();
		exit(0);
	}
	if (erase_begin(el))
		return ;
	while (prev->next)
	{
		cur = prev->next;
		if (cur->is_curr == true)
		{
			prev->next = cur->next;
			prev->is_curr = true;
			free(cur->path);
			free(cur);
			break;
		}
		prev = prev->next;
	}
}

void			key_delete(t_elem **arr, t_term *te, t_elem **el)
{
	key_backspace(arr, te, el);
}