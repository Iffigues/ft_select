/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_charz.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bordenoy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/17 14:11:37 by bordenoy          #+#    #+#             */
/*   Updated: 2019/04/25 12:37:48 by bordenoy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

int		check(t_beg *b)
{
	b->mod = b->mod ^ 1;
	b->tmp.index = 0;
	change_mod(b);
	return (1);
}

int		ft_charz(int a)
{
	return (write(0, &a, 1));
}

int		ft_null(void)
{
	int		i;
	t_beg	*b;

	b = hahaha(NULL, 1);
	i = 0;
	while (i < b->fin.col_size)
		if (b->fin.col[i++].live == 1)
			return (0);
	return (1);
}

void	commence(void)
{
	char			c[8];
	unsigned long	num;
	t_beg			*b;

	b = hahaha(NULL, 1);
	ft_memset(c, '\0', 8);
	aff(b);
	while ((read(b->tty, c, 8)) > 0)
	{
		num = *(unsigned long *)c;
		if (num == ESC_KEY)
		{
			ft_libere(b);
			exit(0);
		}
		if (fleche(num, b))
			if (action(num, b))
				ft_choose(num, b);
		aff(b);
		ft_memset(c, '\0', 8);
	}
}

void	begin(t_beg *ar)
{
	ft_putstr_fd(tgetstr("me", NULL), 0);
	ar->cap[0].len = tgetflag("cl");
	ar->cap[0].name = tgetstr("cl", NULL);
	ar->cap[1].len = tgetflag("cm");
	ar->cap[1].name = tgetstr("cm", NULL);
	ar->cap[2].len = tgetflag("vi");
	ar->cap[2].name = tgetstr("vi", NULL);
	ar->cap[3].len = tgetflag("ve");
	ar->cap[3].name = tgetstr("ve", NULL);
	ft_putstr_fd(ar->cap[2].name, 0);
	ar->mod = 1;
	ar->tmp.index = 0;
	hahaha(ar, 0);
	get_size(ar);
	change_mod(ar);
	commence();
}
