/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bordenoy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/17 17:02:39 by bordenoy          #+#    #+#             */
/*   Updated: 2019/04/19 18:46:47 by bordenoy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

extern t_beg g_beg;

int	count_nbr(void)
{
	int y;
	int h;
	int a;

	h = 0;
	y = 0;
	a = g_beg.mod;
	if (g_beg.tmp.col)
	while (y < g_beg.tmp.col_size)
		if (g_beg.tmp.col[y++].live == a)
			h++;
	return (h);
}

int	count_col(void)
{
	return (g_beg.x / g_beg.tmp.max_size);
}

int	count_raw(void)
{
	int y;
	int u;
	int h;

	h = 0;
	u = count_nbr();
	y = count_col();
	if (y)
		h = (u / y) + 1;
	h++;
	return (h);
}

void	ft_changer()
{
/*	int o;

	o = g_beg.index;
	while (o <= g_beg.col_size)
	{
		if (g_beg.col[o].live == g_beg.mod)
		{
			g_beg.index = o;
			return ;
		}
		o++;
	}
	o = g_beg.index;
	while (o >= 0)
	{
		if (g_beg.col[o].live == g_beg.mod)
			 g_beg.index = o;
		o--;
	}*/
}

int	ft_gap(/*int a, int b, int c*/)
{
/*	int y;

	y = 0;
	if (c < 0)
		while (a != b)
		{
			if (g_beg.col[a].live != g_beg.mod)
				y += 1;
			a--;
		}
	if (c > 0)
	{
		while (a != b)
		{
			if (g_beg.col[a].live != g_beg.mod)
				y += 1;
			a++;
		}
	}
	return (y * c);
	*/
	return (1);
}

void	ft_jump(int a)
{
	int	i;
	int o;
	int	j;

	o = g_beg.tmp.index + a;
	j = count_col() * a;
	i = g_beg.tmp.index + j;
	if (i < g_beg.tmp.col_size && i >= 0)
		g_beg.tmp.index = i;
}

void	ft_move(int a)
{
	int	i;

	i  =  g_beg.tmp.index + a;
	if (i < g_beg.tmp.col_size && i >= 0 )
			g_beg.tmp.index = i;
}
