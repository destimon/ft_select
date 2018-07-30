/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcherend <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/27 13:35:47 by dcherend          #+#    #+#             */
/*   Updated: 2018/07/29 21:06:48 by dcherend         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_select.h"

# define HANDLED_KEYS 11

static void (*key_handler[]) (t_elem **arr, t_term *te, t_elem **el) = {
&key_esc,
&key_left,
&key_right,
&key_up,
&key_down,
&key_return,
&key_space,
&key_backspace,
&key_delete,
&key_pgup,
&key_pgdown
};

void			wait_input(t_elem **arr, t_elem **el, t_term *te)
{
	int			keys[HANDLED_KEYS] =
		{KEY_ESC, L_ARROW, R_ARROW, UP_ARROW, DOWN_ARROW, KEY_RETURN,
		KEY_SPACE, KEY_BACK, KEY_DEL, PG_UP, PG_DOWN };
	long		input;
	int			i;

	input = 0;
	read(0, &input, 8);
	i = 0;
	while (i < HANDLED_KEYS)
	{
		if (input == keys[i])
			(*key_handler[i])(arr, te, el);
		i++;
	}
}