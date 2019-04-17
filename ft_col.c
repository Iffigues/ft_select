/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_col.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bordenoy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/15 17:11:47 by bordenoy          #+#    #+#             */
/*   Updated: 2019/04/15 18:03:15 by bordenoy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

int	get_size(t_beg *opt)
{
	struct winsize	w;
	int				i;

	if ((i = ioctl(STDERR_FILENO, TIOCGWINSZ, &w) > -1))
	{
		opt->x = w.ws_col;
		opt->y = w.ws_row;
	}
	return (i);
}
