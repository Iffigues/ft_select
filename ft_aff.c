/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_aff.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bordenoy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/17 16:59:46 by bordenoy          #+#    #+#             */
/*   Updated: 2019/04/18 04:03:11 by bordenoy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

extern t_beg	g_beg;

static void	blank(size_t a, int b, int h, int y)
{
	size_t k;

	if (!h && (y + 1 != g_beg.col_size))
	{
		k = (size_t)b;
		while (a < k)
		{
			a++;
			tputs(" ", 1, ft_charz);
		}
	}
}

static void setcolor(int i)
{
	char	*af;
	char	*g;

	af = tgetstr("AF", NULL);
	g = tgetstr("AB", NULL);
	tputs(tparm(af, i), 1, ft_charz);
	tputs(tparm(g, 2), 1, ft_charz);
}

static void	fiche(int a, int b)
{
	int	c;
	int d;
	int i;

	if (a + b)
		;
	c = 0;
	d = 0;
	i = 0;
	while (i < g_beg.col_size)
	{
		if (c == a)
		{
			c = 0;
			tputs("\n" , 1, ft_charz);
		}
		if (g_beg.col[i].live == g_beg.mod)
		{
			setcolor(i);
			tputs(g_beg.col[i].name , 1, ft_charz);
			c++;
			blank(g_beg.col[i].len, g_beg.max_size, c == a, i);
		}
		i++;
	}
}

void		aff(void)
{
	int 	a;
	int 	b;

	get_size();
	if (g_beg. x != 0 && g_beg.y != 0)
	{
		if ((a = count_col()) != 0)
			if ((b = count_raw()) < g_beg.y)
			{
				fiche(a, b);
				return ;
			}
	}
}
