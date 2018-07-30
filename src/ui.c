/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcherend <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/29 13:21:56 by dcherend          #+#    #+#             */
/*   Updated: 2018/07/29 17:51:54 by dcherend         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_select.h"

static void		ft_padding(int size)
{
	int			i;

	i = 0;
	while (i < size)
	{
		ft_putstr_fd(" ", 0);
		i++;
	}
}

static void		ft_colorize(t_elem *el)
{
	if (!el->mode)
		ft_putstr_fd(ANSI_COLOR_RED, 0);
	else if (S_ISDIR(el->mode))
		ft_putstr_fd(ANSI_BOLD_GREEN, 0);
	else if (S_ISREG(el->mode))
		ft_putstr_fd(ANSI_BOLD_WHITE, 0);
	else if (S_ISLNK(el->mode))
		ft_putstr_fd(ANSI_COLOR_MAGENTA, 0);
	else if (S_ISBLK(el->mode))
		ft_putstr_fd(ANSI_COLOR_YELLOW, 0);
	else if (S_ISSOCK(el->mode))
		ft_putstr_fd(ANSI_COLOR_BLUE, 0);
	else if (S_ISCHR(el->mode))
		ft_putstr_fd(ANSI_COLOR_CYAN, 0);
	else if (S_ISFIFO(el->mode))
		ft_putstr_fd(ANSI_COLOR_GREEN, 0);
	if (el->is_curr)
		ft_putstr_fd(ANSI_UNDER, 0);
	if (el->is_sel)
		ft_putstr_fd(ANSI_BACK_BLUE, 0);
}

void			print_border_top(t_term *te)
{
	char		*cwd;

	print_border_fence(te->ws_cols);
	ft_putstr_fd("\e[1;97m", 0);
	ft_putstr_fd("[FT_SELECT]\n\n", 0);
	ft_putstr_fd(ANSI_COLOR_RESET, 0);
	cwd = getcwd(NULL, 0);
	ft_putstr_fd(cwd, 0);
	free(cwd);
	ft_putstr_fd("\n", 0);
	print_border_fence(te->ws_cols);
}

void			print_border_bot(t_term *te)
{
	char		buf[1024];
	int			i;

	i = te->ui_rows + 14;
	while (i < te->ws_rows)
	{
		ft_putstr_fd("\n", 0);
		i++;
	}
	print_border_fence(te->ws_cols);
	getlogin_r(buf, 1024);
	ft_putstr_fd(buf, 0);
	gethostname(buf, 1024);
	ft_putstr_fd(" | ", 0);
	ft_putstr_fd(buf, 0);
	ft_putstr_fd("\n", 0);
	print_border_fence(te->ws_cols);
}

void			display_ui(t_elem **arr, t_term *te)
{
	int			i;
	int			j;
	int			curs;

	i = 0;
	print_border_top(te);
	while (i < te->ui_rows - g_pagin)
	{
		j = 0;
		ft_putstr_fd("[", 0);
		ft_putnbr(i);
		ft_putstr_fd("] ", 0);
		while (j < te->ui_cols && (i + j * te->ui_rows) < te->list_len)
		{
			curs = 0;
			ft_colorize(arr[i + j * te->ui_rows]);
			cursor_handler(arr[i + j * te->ui_rows]->is_curr, &curs);
			ft_putstr_fd(arr[i + j * te->ui_rows]->path, 0);
			ft_putstr_fd(ANSI_COLOR_RESET, 0);
			if (j < te->ui_cols - 1)
				ft_padding(te->longest -
					(int)ft_strlen(arr[i + j * te->ui_rows]->path) + 5 - curs);
			j++;
		}
		if (i < te->ui_rows)
			ft_putstr_fd("\n", 0);
		i++;
	}
	print_border_bot(te);
}