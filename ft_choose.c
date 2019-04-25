/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_choose.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bordenoy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/24 11:50:11 by bordenoy          #+#    #+#             */
/*   Updated: 2019/04/25 12:45:54 by bordenoy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void	ft_choose(char num, t_beg *b)
{
	int i;

	i = 0;
	while (i < b->tmp.col_size)
	{
		if (*b->tmp.col[i].name == num)
		{
			b->tmp.index = i;
			return ;
		}
		i++;
	}
}

void	ft_kk(t_beg *b)
{
	if (b->mod == 1)
	{
		if (ct(b))
			ft_sel(b);
	}
	else
	{
		if (ct(b))
		{
			cm(b->tmp.index, b);
			b->tmp.index = 0;
		}
	}
	change_mod(b);
}
