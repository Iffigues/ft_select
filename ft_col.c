/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_col.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bordenoy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/15 17:11:47 by bordenoy          #+#    #+#             */
/*   Updated: 2019/04/17 18:03:18 by bordenoy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

extern t_beg	g_beg;

int	get_size(void)
{
	struct winsize	w;
	int				i;

	if ((i = ioctl(STDERR_FILENO, TIOCGWINSZ, &w) > -1))
	{
		g_beg.x = w.ws_col;
		g_beg.y = w.ws_row;
	}
	return (i);
}
