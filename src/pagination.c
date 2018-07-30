/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pagination.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcherend <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/30 18:41:34 by dcherend          #+#    #+#             */
/*   Updated: 2018/07/30 18:41:35 by dcherend         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_select.h"

void			key_pgup(t_elem **arr, t_term *te, t_elem **el)
{
	if ((g_pagin + 3 <= te->ui_rows - te->ws_rows + 9))
	{
		g_pagin += 3;
	}
}

void			key_pgdown(t_elem **arr, t_term *te, t_elem **el)
{
	if ((g_pagin - 4) >= 0)
	{
		g_pagin -= 4;
	}
}