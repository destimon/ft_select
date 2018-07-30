/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   term.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcherend <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/27 13:39:19 by dcherend          #+#    #+#             */
/*   Updated: 2018/07/29 21:27:18 by dcherend         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_select.h"

void				reset_input_mode(void)
{
	tcsetattr(STDERR_FILENO, TCSANOW, &g_sa);
	tputs(tgetstr("ve", NULL), 1, &complete);
	tputs(tgetstr("te", NULL), 1, &complete);
}

int					complete(int a)
{
	return ((int)write(STDERR_FILENO, &a, 1));
}

void				set_input_mode(void)
{
	struct termios	tattr;
	char			buf[1024];

	if (!isatty(STDIN_FILENO))
	{
		ft_putstr_fd("Not a terminal.\n", 2);
		exit(0);
	}
	tcgetattr(STDIN_FILENO, &g_sa);
	tcgetattr(STDIN_FILENO, &tattr);
	tattr.c_lflag &= ~(ICANON|ECHO);
	tattr.c_cc[VMIN] = 1;
	tattr.c_cc[VTIME] = 0;
	if ((tgetent(buf, getenv("TERM"))) == ERR)
	{
		ft_putstr_fd("TERM environment variable not set.\n", 2);
		ft_putstr_fd("WARNING: terminal is not fully functional\n", 2);
	}
	tputs(tgetstr("vi", NULL), 1, &complete);
	tputs(tgetstr("ti", NULL), 1, &complete);
	tcsetattr(STDERR_FILENO, TCSANOW, &tattr);
}

t_term				*init_term(t_elem **arr, t_elem *el)
{
	struct winsize	ws;
	t_term			*te;

	te = (t_term*)malloc(sizeof(t_term));
	if (!te)
		return (NULL);
	ioctl(0, TIOCGWINSZ, &ws);
	te->ws_cols = ws.ws_col;
	te->ws_rows = ws.ws_row;
	te->list_len = count_list(el);
	te->longest = longest_name(el);
	te->ui_cols = (te->ws_cols) / (te->longest);
	te->ui_cols = (te->ui_cols == 0) ? (1) : (te->ui_cols);
	te->ui_rows = te->list_len / te->ui_cols + 1;
	te->ui_cpos = current_position(arr);
	return (te);
}