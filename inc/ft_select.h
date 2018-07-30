/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcherend <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/27 13:32:38 by dcherend          #+#    #+#             */
/*   Updated: 2018/07/29 21:07:09 by dcherend         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../lib/libft/libft.h"
# include "../lib/libft/get_next_line.h"
# include <stdlib.h>
# include <termcap.h>
# include <stdio.h>
# include <sys/ioctl.h>
# include <signal.h>
# include <termios.h>
# include <dirent.h>
# include <sys/stat.h>
# include <ftw.h>
# include <unistd.h>
# include <sys/param.h>
# include <stdbool.h>

# define ANSI_COLOR_RED		"\x1b[31m"
# define ANSI_COLOR_GREEN	"\x1b[32m"
# define ANSI_COLOR_YELLOW	"\x1b[33m"
# define ANSI_COLOR_BLUE	"\x1b[34m"
# define ANSI_COLOR_MAGENTA	"\x1b[35m"
# define ANSI_COLOR_CYAN	"\x1b[36m"
# define ANSI_COLOR_RESET	"\x1b[0m"
# define ANSI_BOLD_GREEN	"\e[1;32m"
# define ANSI_BOLD_WHITE	"\e[1;37m"
# define ANSI_BACK_BLUE		"\e[7m"
# define ANSI_UNDER			"\e[4m"

/*
** KEYBOARD.
*/
# define KEY_Q		113
# define KEY_ESC	27
# define L_ARROW	4479771
# define R_ARROW	4414235
# define UP_ARROW	4283163
# define DOWN_ARROW	4348699
# define KEY_SPACE	32
# define KEY_RETURN	10
# define KEY_BACK	127
# define KEY_DEL	2117294875
# define PG_UP		2117425947
# define PG_DOWN	2117491483

struct termios		g_sa;
int					g_pagin;

typedef struct		s_term
{
	int				ws_cols;
	int				ws_rows;
	int				list_len;
	int				longest;
	int				ui_cols;
	int				ui_rows;
	int				ui_cpos;
}					t_term;

typedef struct		s_elem
{
	char			*path;
	_Bool			is_curr;
	_Bool			is_sel;
	mode_t			mode;
	struct s_elem	*next;
}					t_elem;

void				init_loop(t_elem **arr, t_elem *el);

/*
** TERM.
*/
t_term				*init_term(t_elem **arr, t_elem *el);
void				set_input_mode(void);
void				reset_input_mode(void);
int					complete(int a);

/*
** UI.
*/
void				display_ui(t_elem **arr, t_term *te);

/*
** LIST.
*/
t_elem				*init_list(const char **files);
t_elem				**obtain_list(t_elem *el);

/*
** CORE.
*/
void				wait_input(t_elem **arr, t_elem **el, t_term *te);

/*
** INPUT.
*/
void				key_esc(t_elem **arr, t_term *te, t_elem **el);
void				key_return(t_elem **arr, t_term *te, t_elem **el);
void				key_space(t_elem **arr, t_term *te, t_elem **el);
void				key_backspace(t_elem **arr, t_term *te, t_elem **el);
void				key_delete(t_elem **arr, t_term *te, t_elem **el);

/*
** INPUT2.
*/
void				key_left(t_elem **arr, t_term *te, t_elem **el);
void				key_right(t_elem **arr, t_term *te, t_elem **el);
void				key_up(t_elem **arr, t_term *te, t_elem **el);
void				key_down(t_elem **arr, t_term *te, t_elem **el);

/*
** UTILS.
*/
int					count_list(t_elem *el);
int					longest_name(t_elem *el);
int					current_position(t_elem **arr);

/*
** SIGNALS.
*/
void				signals(t_term *te, t_elem **arr, t_elem *el);

/*
** PAGINATION.
*/
void				key_pgup(t_elem **arr, t_term *te, t_elem **el);
void				key_pgdown(t_elem **arr, t_term *te, t_elem **el);

/*
** EXTEND.
*/
int					erase_begin(t_elem **el);
void				cursor_handler(_Bool is_curr, int *curs);
void				print_border_fence(int limit);
