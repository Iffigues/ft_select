/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_begin.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bordenoy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/15 14:42:58 by bordenoy          #+#    #+#             */
/*   Updated: 2019/04/25 12:21:19 by bordenoy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

size_t	sizer(t_beg *b)
{
	size_t	a;
	int		i;

	a = 0;
	i = 0;
	if (b->tmp.col)
		while (i < b->tmp.col_size)
		{
			if (b->tmp.col[i].len > a)
				a = b->tmp.col[i].len;
			i++;
		}
	return (a);
}

int		fleche(unsigned long j, t_beg *b)
{
	if (j == RIGHT_KEY)
	{
		ft_move(1, b);
		return (0);
	}
	if (j == LEFT_KEY)
	{
		ft_move(-1, b);
		return (0);
	}
	if (j == DOWN_KEY && ((b->tmp.index + count_col(b)) < count_nbr(b) + 1))
	{
		ft_jump(1, b);
		return (0);
	}
	if (j == UP_KEY && ((b->tmp.index - count_col(b)) >= 0))
	{
		ft_jump(-1, b);
		return (0);
	}
	return (1);
}

void	cm(int i, t_beg *b)
{
	int c;

	c = b->tmp.col[i].index;
	b->fin.col[c].live = b->fin.col[c].live ^ 1;
}

void	mc(int y, t_beg *b)
{
	int c;

	c = b->tmp.col[y].index;
	b->fin.col[c].choice = b->fin.col[c].choice ^ 1;
}

int		action(unsigned long j, t_beg *b)
{
	if (j == MODE)
	{
		check(b);
		return (0);
	}
	if ((j == DD || j == DEL) && b->mod == 1)
	{
		chack(b);
		return (0);
	}
	if (j == SPACE)
	{
		if (b->good)
			ft_kk(b);
		return (0);
	}
	if (j == ENTER && b->mod == 1)
		enter(b);
	return (1);
}
