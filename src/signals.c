/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcherend <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/29 17:23:23 by dcherend          #+#    #+#             */
/*   Updated: 2018/07/29 21:33:01 by dcherend         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_select.h"

t_elem		**s_elements;
t_elem		*s_el;
t_term		*s_terminformation;

static void		ignore(int sig)
{
	int			i;

	i = 42;
}

static void		restore(int sig)
{
	if (sig == SIGINT)
	{
		reset_input_mode();
		exit(0);
	}
	else if (sig == SIGTSTP)
	{
		tputs(tgetstr("cl", NULL), 1, &complete);
		tputs(tgetstr("ve", NULL), 1, &complete);
		ioctl(STDERR_FILENO, TIOCSTI, "\x1A");
		reset_input_mode();
		signal(SIGTSTP, SIG_DFL);
	}
	else
	{
		reset_input_mode();
		exit(0);
	}
}

static void		getback(int sig)
{
	t_term		*ti;

	if (sig == SIGCONT)
	{
		set_input_mode();
		init_loop(s_elements, s_el);
		set_input_mode();
	}
	else
	{
		tputs(tgetstr("cl", NULL), 1, &complete);
		ti = init_term(s_elements, s_el);
		display_ui(s_elements, ti);
		g_pagin = 0;
		free(ti);
	}
}

void			signals(t_term *te, t_elem **arr, t_elem *el)
{
	s_elements = arr;
	s_terminformation = te;
	s_el = el;

	signal(SIGINT, &restore);
	signal(SIGTSTP, &restore);
	signal(SIGCONT, &getback);
	signal(SIGWINCH, &getback);
	signal(SIGABRT, &restore);
	signal(SIGKILL, &restore);
	signal(SIGQUIT, &restore);
}