/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_libere.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bordenoy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/15 14:05:34 by bordenoy          #+#    #+#             */
/*   Updated: 2019/04/25 12:48:51 by bordenoy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void	ft_freeze(char *b)
{
	if (b)
		free(b);
}

void	ft_libere(t_beg *ar)
{
	int		i;
	char	*reset_cmd;

	reset_cmd = tgetstr("me", NULL);
	ft_putstr_fd(reset_cmd, ar->tty);
	ft_putstr_fd(ar->cap[3].name, ar->tty);
	ft_putstr_fd(ar->cap[0].name, ar->tty);
	tcsetattr(STDERR_FILENO, 0, &ar->oldt);
	tputs(tgetstr("te", NULL), 1, ft_charz);
	fun(ar);
	i = 0;
	if (ar->fin.col)
	{
		while (i < ar->fin.col_size)
		{
			if (ar->fin.col[i].name)
				free(ar->fin.col[i].name);
			i++;
		}
		free(ar->fin.col);
	}
}

void	ft_sel(t_beg *b)
{
	if (ct(b))
	{
		mc(b->tmp.index, b);
		ft_move(1, b);
	}
}
