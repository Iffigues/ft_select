/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_begin.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bordenoy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/15 14:42:58 by bordenoy          #+#    #+#             */
/*   Updated: 2019/04/19 20:33:37 by bordenoy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

extern	t_beg g_beg;

size_t	sizer()
{
	size_t	a;
	int		i;

	a = 0;
	i = 0;
	if (g_beg.tmp.col)
		while (i < g_beg.tmp.col_size)
		{
			if (g_beg.tmp.col[i].len > a)
				a = g_beg.tmp.col[i].len;
			i++;
		}
	return (a);
}

static void		fleche(unsigned long j)
{
	if (j == RIGHT_KEY)
	{
		ft_move(1);
	}
	if (j == LEFT_KEY && g_beg.tmp.index > 0)
	{
		ft_move(-1);
	}
	if (j == DOWN_KEY && ((g_beg.tmp.index + count_col()) < count_nbr() + 1))
	{
		ft_jump(1);
	}
	if (j == UP_KEY && ((g_beg.tmp.index - count_col() ) >= 0))
	{
		ft_jump(-1);
	}
}

void			cm(int i)
{
	int c;

	c = g_beg.tmp.col[i].index;
	g_beg.fin.col[c].live = g_beg.fin.col[c].live ^ 1; 
}

void		mc(int y)
{
	int c;

	c = g_beg.tmp.col[y].index;
	g_beg.fin.col[c].choice = g_beg.fin.col[c].choice ^ 1;

}

static int		action(unsigned long j)
{
	if (j == MODE)
	{
		g_beg.mod = g_beg.mod ^ 1;
		g_beg.tmp.index = 0;
		change_mod();
		return (1);
	}
	if (j == DD || j == DEL)
	{
		cm(g_beg.tmp.index);
		ft_changer();
		change_mod();
		return (1);
	}
	if (j == SPACE)
	{
		mc(g_beg.tmp.index);
		return (1);
	}
	return (0);
}

void		commence(void)
{
	char			c[8];
	unsigned long	num;

	ft_memset(c, '\0', 8);
	aff();
	while ((read(STDERR_FILENO, c, 8)) > 0)
	{
		num = *(unsigned long *)c;
		if (num == ESC_KEY)
			break ;
		fleche(num);
		action(num);
		aff();
		ft_memset(c, '\0', 8);
	}
}

void			begin(t_beg *ar)
{
	char    *reset_cmd;

	reset_cmd = tgetstr("me", NULL);
	tputs(reset_cmd, 1, ft_charz);
	ar->cap[0].len = tgetflag("cl");
	ar->cap[0].name = tgetstr("cl", NULL);
	ar->cap[1].len = tgetflag("cm");
	ar->cap[1].name = tgetstr("cm", NULL);
	ar->cap[2].len = tgetflag("vi");
	ar->cap[2].name = tgetstr("vi", NULL);
	ar->cap[3].len = tgetflag("ve");
	ar->cap[3].name = tgetstr("ve", NULL);
	tputs(ar->cap[2].name, 1, ft_charz);
	ar->mod = 1;
	g_beg = *ar;
	get_size();
	change_mod();
	commence();
}
