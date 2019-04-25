/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bordenoy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/17 17:02:39 by bordenoy          #+#    #+#             */
/*   Updated: 2019/04/24 17:19:59 by bordenoy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

int		count_nbr(t_beg *b)
{
	int y;
	int h;
	int a;

	h = 0;
	y = 0;
	a = b->mod;
	if (b->tmp.col)
		while (y < b->tmp.col_size)
			if (b->tmp.col[y++].live == a)
				h++;
	return (h);
}

int		count_col(t_beg *b)
{
	return (b->x / b->tmp.max_size);
}

int		count_raw(t_beg *b)
{
	int y;
	int u;
	int h;

	h = 0;
	u = count_nbr(b);
	y = count_col(b);
	if (y)
		h = (u / y) + 1;
	h++;
	return (h);
}

void	ft_jump(int a, t_beg *b)
{
	int	i;
	int o;
	int	j;

	o = b->tmp.index + a;
	j = count_col(b) * a;
	i = b->tmp.index + j;
	if (i < b->tmp.col_size && i >= 0)
		b->tmp.index = i;
}

void	ft_move(int a, t_beg *b)
{
	int	i;

	i = b->tmp.index + a;
	if (i >= b->tmp.col_size)
		b->tmp.index = 0;
	else if (i < 0)
		b->tmp.index = b->tmp.col_size - 1;
	else if (i < b->tmp.col_size && i >= 0)
		b->tmp.index = i;
}
