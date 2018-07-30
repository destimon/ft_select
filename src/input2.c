/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcherend <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/29 15:00:38 by dcherend          #+#    #+#             */
/*   Updated: 2018/07/29 21:03:50 by dcherend         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_select.h"

void			key_left(t_elem **arr, t_term *te, t_elem **el)
{
	if (te->ui_cpos - te->ui_rows >= 0)
	{
		arr[te->ui_cpos]->is_curr = false;
		te->ui_cpos -= te->ui_rows;
		arr[te->ui_cpos]->is_curr = true;
	}
}

void			key_right(t_elem **arr, t_term *te, t_elem **el)
{
	if (te->ui_cpos + te->ui_rows < te->list_len)
	{
		arr[te->ui_cpos]->is_curr = false;
		te->ui_cpos += te->ui_rows;
		arr[te->ui_cpos]->is_curr = true;
	}
}

void			key_up(t_elem **arr, t_term *te, t_elem **el)
{
	if (te->ui_cpos - 1 >= 0)
	{
		arr[te->ui_cpos]->is_curr = false;
		te->ui_cpos -= 1;
		arr[te->ui_cpos]->is_curr = true;
	}
	else
	{
		arr[te->ui_cpos]->is_curr = false;
		te->ui_cpos = te->list_len - 1;
		arr[te->ui_cpos]->is_curr = true;
	}
}

void			key_down(t_elem **arr, t_term *te, t_elem **el)
{
	if (te->ui_cpos + 1 < te->list_len)
	{
		arr[te->ui_cpos]->is_curr = false;
		te->ui_cpos += 1;
		arr[te->ui_cpos]->is_curr = true;
	}
	else
	{
		arr[te->ui_cpos]->is_curr = false;
		te->ui_cpos = 0;
		arr[te->ui_cpos]->is_curr = true;
	}
}