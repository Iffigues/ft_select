/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_aff.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bordenoy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/17 16:59:46 by bordenoy          #+#    #+#             */
/*   Updated: 2019/04/17 20:45:10 by bordenoy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

extern t_beg	g_beg;

void	aff(void)
{
	int 	a;
	int 	b;

	get_size();
	if (g_beg. x != 0 && g_beg.y != 0)
	{
		if ((a = count_col()) != 0)
			if ((b = count_raw()) < g_beg.y)
			{
				printf("haha\n");			
				return ;
			}
	}
}
