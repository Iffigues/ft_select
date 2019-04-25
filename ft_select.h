/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bordenoy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/22 13:23:16 by bordenoy          #+#    #+#             */
/*   Updated: 2019/04/25 12:47:25 by bordenoy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SELECT_H
# define FT_SELECT_H

# include <unistd.h>
# include "libft/libft.h"
# include <termcap.h>
# include <signal.h>
# include <stdlib.h>
# include <sys/ioctl.h>
# include <termios.h>
# include <term.h>
# include <fcntl.h>
# include <sys/stat.h>

# define ENTER		10
# define ESC_KEY	27
# define RIGHT_KEY	4414235
# define LEFT_KEY	4479771
# define UP_KEY		4283163
# define DOWN_KEY	4348699
# define SPACE		32
# define DEL		127
# define DD			2117294875
# define MODE		5921563

typedef struct		s_col
{
	int				index;
	int				type;
	char			*name;
	int				live;
	int				choice;
	size_t			len;
}					t_col;

typedef struct		s_bag
{

	int				index;
	t_col			*col;
	int				col_size;
	int				col_nbr;
	int				max_size;
}					t_bag;

typedef struct		s_beg
{
	struct termios	oldt;
	struct termios	newt;
	int				x;
	int				y;
	int				mod;
	char			*term;
	int				atti;
	int				tgent;
	int				tty;
	int				slot;
	int				good;
	t_col			cap[8];
	t_bag			fin;
	t_bag			tmp;
}					t_beg;

t_beg				*hahaha(t_beg *h, int i);
void				ft_kk(t_beg *b);
void				ft_choose(char h, t_beg *b);
void				cm(int y, t_beg *b);
void				mc(int y, t_beg *b);
void				ft_sel(t_beg *b);
void				enter(t_beg *b);
int					check(t_beg *b);
int					fleche(unsigned long j, t_beg *b);
int					action(unsigned long j, t_beg *b);
int					setu(int i, t_beg *t);
int					ct();
void				fun();
int					ft_type(char *b);
int					ft_null();
size_t				sizer();
void				change_mod();
void				ft_changer();
void				ft_jump(int a, t_beg *b);
void				ft_move(int a, t_beg *b);
void				commence(void);
void				background(t_beg *b);
void				aff(t_beg *b);
int					count_nbr(t_beg *b);
int					count_raw(t_beg *b);
int					ft_charz(int a);
int					get_size(t_beg *b);
void				ft_libere(t_beg *ar);
void				begin(t_beg *ar);
void				grab_sign(void);
int					count_col(t_beg *b);
int					chack(t_beg *b);
void				ft_freeze(char *b);

#endif
