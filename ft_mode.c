/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mode.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bordenoy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/19 16:54:11 by bordenoy          #+#    #+#             */
/*   Updated: 2019/04/19 20:31:00 by bordenoy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

extern t_beg	g_beg;

void	fun()
{
	int i;

	i = 0;
	if (g_beg.tmp.col)
	{
		while (i < g_beg.tmp.col_size)
		{
			if (g_beg.tmp.col[i].name)
				free(g_beg.tmp.col[i].name);
			i++;
		}
		free(g_beg.tmp.col);
	}
	g_beg.tmp.col = NULL;
}

int static ct()
{
	int h;
	int y;

	y = 0;
	h = 0;
	while (g_beg.fin.col_size > h)
	{
		if (g_beg.fin.col[h].live == g_beg.mod)
			y++;
		h++;
	}
	return (y);
}

t_col	*ft_colcpy()
{
	int		i;
	int		y;
	int 	u;
	t_col 	*p;

	y = 0;
	u = 0;
	i = ct();
	if (!(p = (t_col *)malloc(sizeof(t_col) * (i))))
		return (NULL);
	g_beg.tmp.col_size = i;
	while (y < g_beg.fin.col_size)
	{
		if (g_beg.fin.col[y].live == g_beg.mod)
		{
			p[u].index = g_beg.fin.col[y].index;
			p[u].live = g_beg.fin.col[y].live;
			p[u].name = ft_strdup(g_beg.fin.col[y].name);
			p[u].len = g_beg.fin.col[y].len;
			u++;
		}
		y++;		
	}
	return (p);
}

void change_mod()
{
	t_bag	tmp;

	fun();
	tmp.index = g_beg.tmp.index;
	tmp.col = ft_colcpy();
	tmp.max_size = 0;
	tmp.col_size = ct();
	g_beg.tmp = tmp;	
	g_beg.tmp.max_size = sizer() + 1;
	
}
