/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_background.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bordenoy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/19 10:45:42 by bordenoy          #+#    #+#             */
/*   Updated: 2019/04/19 10:48:40 by bordenoy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

extern t_beg	g_beg;

void	background(void)
{
	char    *g;

	g = tgetstr("AB", NULL);
	tputs(tparm(g, 2), 1, ft_charz);
	tputs(g_beg.cap[0].name, 1, ft_charz);\
}
