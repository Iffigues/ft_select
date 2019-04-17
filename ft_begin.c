/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_begin.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bordenoy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/15 14:42:58 by bordenoy          #+#    #+#             */
/*   Updated: 2019/04/17 15:17:26 by bordenoy         ###   ########.fr       */
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

static void		commence(void)
{
	char			c[8];
	unsigned long	num;

	ft_memset(c, '\0', 8);
	while ((read(STDERR_FILENO, c, 8)) > 0)
	{
		num = *(unsigned long *)c;
		if (num == ESC_KEY)
			exit(0);
		else
			printf("%lu\n", num);
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
