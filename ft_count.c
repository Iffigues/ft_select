/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bordenoy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/17 17:02:39 by bordenoy          #+#    #+#             */
/*   Updated: 2019/04/19 13:04:33 by bordenoy         ###   ########.fr       */
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
	while (y < g_beg.col_size)
		if (g_beg.col[y++].live == a)
			h++;
	return (h);
}

int	count_col(void)
{
	return (g_beg.x / g_beg.max_size);
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

void	ft_jump(int a)
{
	int	i;
	int	j;

	j = count_col() * a;
	i = g_beg.index + j;
	while (i <= g_beg.col_size && i >= 0 )
	{
		if (g_beg.col[i].live == g_beg.mod)
		{
			g_beg.index = i;
			break ;
		}
		i += j;
	}
}

void	ft_move(int a)
{
	int	i;
	int h;

	h = 1;
	i  =  g_beg.index + a;
	while (i <= g_beg.col_size && i >= 0 )
	{
		if (g_beg.col[i].live == g_beg.mod)
		{
			g_beg.index += (h * a);
			break ;
		}
		i += a;
		h++;
	}
}
