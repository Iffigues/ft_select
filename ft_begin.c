/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_begin.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bordenoy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/15 14:42:58 by bordenoy          #+#    #+#             */
/*   Updated: 2019/04/17 18:32:06 by bordenoy         ###   ########.fr       */
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
	if (j == RIGHT_KEY && g_beg.index < (count_nbr() - 1))
		g_beg.index++;
	if (j == LEFT_KEY && g_beg.index > 0)
		g_beg.index--;
	if (j == UP_KEY && ((g_beg.index + count_col()) < count_nbr()))
		g_beg.index++;
	if (j == DOWN_KEY && ((g_beg.index - count_col()) >= 0))
		g_beg.index--;
	printf("%d\n", count_raw());
}

static void		action(unsigned long j)
{
	if (j == MODE)
		g_beg.mod = g_beg.mod ^ 1;
	if (j == DD || j == DEL)
		g_beg.col[g_beg.index].live = g_beg.col[g_beg.index].live ^ 1;
	if (j == SPACE)
		g_beg.col[g_beg.index].choice = g_beg.col[g_beg.index].choice ^ 1;
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
		action(num);
		ft_memset(c, '\0', 8);
	}
}

void			begin(t_beg *ar)
{
	ar->cap[0].len = tgetflag("cl");
	ar->cap[0].name = tgetstr("cl", NULL);
	tputs(ar->cap[0].name, 1, ft_charz);
	ar->index = 0;
	ar->mod = 1;
	ar->max_size = sizer(ar->col, ar->col_size);
	g_beg = *ar;
	get_size();
	commence();
}
