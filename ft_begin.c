/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_begin.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bordenoy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/15 14:42:58 by bordenoy          #+#    #+#             */
/*   Updated: 2019/04/17 16:33:35 by bordenoy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

extern	t_beg g_beg;

static size_t	sizer(t_col *col, int nb)
{
	size_t	a;
	int		i;

	a = 0;
	i = 0;
	while (i < nb)
	{
		if (col[i].len > a)
			a = col[i].len;
		i++;
	}
	return (a);
}

static void		fleche(unsigned long j)
{
	if (j == RIGHT_KEY && g_beg.index < (g_beg.col_size - 1))
		g_beg.index++;
	if (j == LEFT_KEY && g_beg.index > 0)
		g_beg.index--;
	if (j == UP_KEY && ((g_beg.index + g_beg.x) < g_beg.col_size))
		g_beg.index += g_beg.x;
	if (j == DOWN_KEY && ((g_beg.index - g_beg.x) >= 0))
		g_beg.index -= g_beg.x;
}

static void		commence(void)
{
	char			c[8];
	unsigned long	num;

	ft_memset(c, '\0', 8);
	while ((read(STDERR_FILENO, c, 8)) > 0)
	{
		num = *(unsigned long *)c;
		if (num == ESC_KEY)
			break ;
		fleche(num);
		ft_memset(c, '\0', 8);
	}
}

void			begin(t_beg *ar)
{
	ar->cap[0].len = tgetflag("cl");
	ar->cap[0].name = tgetstr("cl", NULL);
	tputs(ar->cap[0].name, 1, ft_charz);
	ar->index = 0;
	ar->max_size = sizer(ar->col, ar->col_size);
	g_beg = *ar;
	commence();
}
