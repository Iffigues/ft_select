/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bordenoy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/22 13:23:16 by bordenoy          #+#    #+#             */
/*   Updated: 2019/04/18 03:28:21 by bordenoy         ###   ########.fr       */
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
# include <stdio.h>
# include <fcntl.h>

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
	char			*name;
	int				live;
	int				choice;
	size_t			len;
}					t_col;

typedef struct		s_beg
{
	struct termios	oldt;
	struct termios	newt;
	int				x;
	int				y;
	int				mod;
	int				index;
	char			*term;
	int				atti;
	int				tgent;
	int				tty;
	int				slot;
	t_col			*col;
	t_col			cap[8];
	int				col_size;
	int				col_nbr;
	int				max_size;
}					t_beg;

void				aff(void);
int					count_nbr();
int					count_raw(void);
int					ft_charz(int a);
int					get_size(void);
void				ft_libere(t_beg ar);
void				begin(t_beg *ar);
void				grab_sign(void);
int					count_col(void);

#endif
