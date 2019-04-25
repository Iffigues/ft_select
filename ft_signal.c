/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_signal.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bordenoy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/27 15:37:42 by bordenoy          #+#    #+#             */
/*   Updated: 2019/04/25 17:01:57 by bordenoy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

static void	fep(t_beg *b)
{
	int i;

	i = 0;
	ft_putstr_fd(tgetstr("me", NULL), b->tty);
	ft_putstr_fd(b->cap[3].name, b->tty);
	ft_putstr_fd(b->cap[0].name, b->tty);
	tcsetattr(STDERR_FILENO, 0, &b->oldt);
	ft_putstr_fd(tgetstr("te", NULL), b->tty);
	while (i != SIGCONT && i < NSIG)
		signal(i++, SIG_DFL);
	ioctl(0, TIOCSTI, (int[]){b->oldt.c_cc[VSUSP], 0});
}

static void	sig_handler(int signo)
{
	t_beg *b;

	b = hahaha(NULL, 1);
	if (signo == SIGINT)
	{
		ft_libere(b);
		exit(0);
	}
	if (signo == SIGWINCH)
		aff(b);
	if (signo == SIGCONT)
	{
		tcgetattr(STDERR_FILENO, &b->oldt);
		b->newt = b->oldt;
		b->newt.c_lflag &= ~ECHO;
		b->newt.c_lflag &= ~ICANON;
		tputs(tgetstr("ti", NULL), 1, ft_charz);
		ft_putstr_fd(b->cap[2].name, 0);
		grab_sign();
		tcsetattr(STDIN_FILENO, 0, &b->newt);
		aff(b);
	}
	if (signo == SIGTSTP)
		fep(b);
}

void		grab_sign(void)
{
	int	i;

	i = 0;
	while (i < NSIG)
	{
		if (i != 11 && signal(i, sig_handler) == SIG_ERR)
			ft_putstr("");
		i++;
	}
}
