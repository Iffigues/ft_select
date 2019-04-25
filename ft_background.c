/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_background.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bordenoy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/19 10:45:42 by bordenoy          #+#    #+#             */
/*   Updated: 2019/04/25 10:52:47 by bordenoy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

extern t_beg	g_beg;

void	background(t_beg *b)
{
	ft_putstr_fd(tparm(tgetstr("AB", NULL), 2), b->tty);
	ft_putstr_fd(b->cap[0].name, b->tty);
}

int		chack(t_beg *b)
{
	if (ft_null())
	{
		ft_libere(b);
		exit(0);
	}
	cm(b->tmp.index, b);
	change_mod(b);
	return (1);
}
