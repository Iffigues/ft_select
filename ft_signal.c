/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_signal.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bordenoy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/27 15:37:42 by bordenoy          #+#    #+#             */
/*   Updated: 2019/04/15 19:38:36 by bordenoy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

extern t_beg g_beg;

static void	sig_handler(int signo)
{
	if (signo == SIGWINCH)
		;
}

void		grab_sign(void)
{
	int	i;

	i = 0;
	while (i < NSIG)
		if (i != SIGUSR2)
		{
			if (signal(i++, sig_handler) == SIG_ERR)
				ft_putstr("");
		}
		else
			i++;
}
