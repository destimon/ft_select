/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcherend <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/14 15:59:57 by dcherend          #+#    #+#             */
/*   Updated: 2018/07/29 21:08:10 by dcherend         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_select.h"

//◦ isatty, ttyname, ttyslot
//◦ ioctl
//◦ getenv
//◦ tcsetattr, tcgetattr
//◦ tgetent, getflag, tgetnum, tgetstr, tgoto, tputs
//◦ open, close, write
//◦ malloc, free
//◦ read, exit
//◦ signal

static void			warn(void)
{
	ft_putstr("ft_select: ");
	ft_putstr(ANSI_COLOR_RED);
	ft_putendl("Not enough args");
	ft_putstr(ANSI_COLOR_RESET);
	ft_putendl("\nusage:\n\tft_select [filename ... ]");
}

void				init_loop(t_elem **arr, t_elem *el)
{
	t_term			*te;

	set_input_mode();
	te = init_term(arr, el);
	te->ui_cpos = 0;
	signals(te, arr, el);
	while (is_user_a_goat())
	{
		free(arr);
		free(te);
		arr = obtain_list(el);
		te = init_term(arr, el);
		signals(te, arr, el);
		display_ui(arr, te);
		wait_input(arr, &el, te);
		tputs(tgetstr("cl", NULL), 1, &complete);
	}
	reset_input_mode();
}

int					main(int argc, const char **argv)
{
	t_elem			**arr;
	t_elem			*el;

	if (argc > 1)
	{
		g_pagin = 0;
		el = init_list(&argv[1]);
		arr = obtain_list(el);
		init_loop(arr, el);
	}
	else
		warn();
	return (0);
}
