/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_libere.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bordenoy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/15 14:05:34 by bordenoy          #+#    #+#             */
/*   Updated: 2019/04/17 14:15:30 by bordenoy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void	ft_libere(t_beg ar)
{
	int		i;
	char	*reset_cmd;

	reset_cmd = tgetstr("me", NULL);
	tputs(reset_cmd, 1, ft_charz);
	tcsetattr(STDERR_FILENO, 0, &ar.oldt);
	i = 0;
	if (ar.col)
	{
		while (i < ar.col_size)
		{
			if (ar.col[i].name)
				free(ar.col[i].name);
			i++;
		}
		free(ar.col);
	}
}
