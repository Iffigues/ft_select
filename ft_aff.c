/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_aff.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bordenoy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/17 16:59:46 by bordenoy          #+#    #+#             */
/*   Updated: 2019/04/25 12:20:23 by bordenoy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

static void	blank(t_beg g, int h, int y)
{
	size_t	k;
	int		i;

	i = g.tmp.col[y].len;
	k = (size_t)g.tmp.max_size;
	if (!h && (y + 1 != g.tmp.col_size))
	{
		while ((int)i++ < (int)k)
			ft_putstr_fd(" ", g.tty);
	}
	else
	{
		while ((int)i++ < (int)k - 1)
			ft_putstr_fd(" ", g.tty);
	}
}

static int	setme(int i, t_beg *g)
{
	ft_putstr_fd(tgetstr("me", NULL), 0);
	if (i == g->tmp.index)
	{
		ft_putstr_fd(tparm(tgetstr("us", NULL), 0), g->tty);
		return (4);
	}
	if (g->tmp.col[i].choice == 0)
		return (g->tmp.col[i].type);
	if (g->tmp.col[i].choice == 1)
		ft_putstr_fd(tgetstr("rv", NULL), g->tty);
	return (0);
}

static void	setcolor(int i, t_beg *g)
{
	int		y;
	int		u;

	y = setme(i, g);
	u = setu(i, g);
	ft_putstr_fd(tparm(tgetstr("AF", NULL), y), g->tty);
	ft_putstr_fd(tparm(tgetstr("AB", NULL), u), g->tty);
}

static void	fiche(int a, t_beg *g)
{
	int	c;
	int d;
	int i;

	c = 0;
	d = 0;
	i = 0;
	while (i < g->tmp.col_size)
	{
		if (c == a)
		{
			c = 0;
			ft_putstr_fd("\n", g->tty);
		}
		if (g->tmp.col[i].live == g->mod)
		{
			setcolor(i, g);
			ft_putstr_fd(g->tmp.col[i].name, g->tty);
			c++;
			blank(*g, c == a, i);
		}
		i++;
	}
}

void		aff(t_beg *g)
{
	int	a;
	int	b;

	get_size(g);
	background(g);
	if (g->x != 0 && g->y != 0)
	{
		if ((a = count_col(g)) != 0)
			if ((b = count_raw(g)) < g->y)
			{
				g->good = 1;
				fiche(a, g);
				return ;
			}
	}
	{
		ft_putstr_fd("not enougth place", g->tty);
		g->good = 0;
	}
}
