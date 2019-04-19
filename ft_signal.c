/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_signal.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bordenoy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/27 15:37:42 by bordenoy          #+#    #+#             */
/*   Updated: 2019/04/19 11:39:47 by bordenoy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

extern t_beg g_beg;

static void	sig_handler(int signo)
{
	if (signo == SIGINT)
	{
		ft_libere(g_beg);
		exit(0);
	}
	if (signo == SIGWINCH)
		aff();
	if (signo == SIGCONT)
	{
		tcgetattr(STDERR_FILENO, &g_beg.oldt);
		g_beg.newt = g_beg.oldt;
		g_beg.newt.c_lflag &= ~ECHO;
		g_beg.newt.c_lflag &= ~ICANON;
		tcsetattr(STDERR_FILENO, 0, &g_beg.newt);
		aff();
		commence();
	}
}

void		grab_sign(void)
{
	int	i;

	i = 0;
	while (i < NSIG)
		if (i != SIGTSTP)
		{
			if (signal(i++, sig_handler) == SIG_ERR)
				ft_putstr("");
		}
		else
			i++;
}
