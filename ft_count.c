/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bordenoy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/17 17:02:39 by bordenoy          #+#    #+#             */
/*   Updated: 2019/04/17 17:30:54 by bordenoy         ###   ########.fr       */
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
