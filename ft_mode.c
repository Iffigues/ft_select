/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mode.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bordenoy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/19 16:54:11 by bordenoy          #+#    #+#             */
/*   Updated: 2019/04/25 12:49:08 by bordenoy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void	fun(t_beg *b)
{
	int i;

	i = 0;
	if (b->tmp.col)
	{
		while (i < b->tmp.col_size)
		{
			if (b->tmp.col[i].name)
				free(b->tmp.col[i].name);
			i++;
		}
		free(b->tmp.col);
	}
	b->tmp.col = NULL;
}

int		ct(t_beg *b)
{
	int h;
	int y;

	y = 0;
	h = 0;
	if (b->fin.col)
		while (h < b->fin.col_size)
		{
			if (b->fin.col[h].live == b->mod)
				y++;
			h++;
		}
	return (y);
}

int		gt(int a, int y)
{
	if (a <= y)
		return (a - 1);
	return (y);
}

t_col	*ft_colcpy(int i, t_beg *b)
{
	int		y;
	int		u;
	t_col	*p;

	y = 0;
	u = 0;
	if (!(p = (t_col *)malloc(sizeof(t_col) * (i))))
		return (NULL);
	b->tmp.col_size = i;
	while (y < b->fin.col_size)
	{
		if (b->fin.col[y].live == b->mod)
		{
			p[u].choice = b->fin.col[y].choice;
			p[u].index = b->fin.col[y].index;
			p[u].type = b->fin.col[y].type;
			p[u].live = b->fin.col[y].live;
			p[u].name = ft_strdup(b->fin.col[y].name);
			p[u].len = b->fin.col[y].len;
			u++;
		}
		y++;
	}
	return (p);
}

void	change_mod(t_beg *b)
{
	t_bag	tmp;

	fun(b);
	tmp.col = NULL;
	tmp.index = 0;
	tmp.index = gt(ct(b), b->tmp.index);
	tmp.col_size = ct(b);
	tmp.col = ft_colcpy(tmp.col_size, b);
	tmp.max_size = 0;
	b->tmp = tmp;
	b->tmp.max_size = sizer(b) + 1;
}
