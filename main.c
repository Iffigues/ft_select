/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bordenoy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/15 11:19:34 by bordenoy          #+#    #+#             */
/*   Updated: 2019/04/24 19:16:56 by bordenoy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

t_col	*make_col(char **b, int ac)
{
	t_col	*p;
	int		i;
	int		h;

	i = 0;
	h = 0;
	if (!(p = (t_col *)malloc(sizeof(t_col) * ac)))
		return (NULL);
	while (b[i])
	{
		p[i].index = h++;
		p[i].choice = 0;
		p[i].type = ft_type(b[i]);
		p[i].live = 1;
		p[i].len = ft_strlen(b[i]);
		p[i].name = ft_strdup(b[i]);
		i++;
	}
	return (p);
}

t_col	*ft_beg(t_beg *ar, char **b, int ac)
{
	char	*bb;

	bb = ttyname(0);
	ar->tgent = 0;
	ar->fin.col = NULL;
	ar->mod = 1;
	ar->fin.col_size = ac;
	ar->fin.col_nbr = ac;
	if ((ar->tty = open(bb, O_RDWR) == -1))
	{
		ft_freeze(bb);
		return (NULL);
	}
	ft_freeze(bb);
	if (!(ar->term = getenv("TERM")))
		return (NULL);
	if ((ar->tgent = tgetent(NULL, ar->term)) < 1)
		return (NULL);
	tputs(tgetstr("ti", NULL), 0, ft_charz);
	tcgetattr(ar->tty, &ar->oldt);
	ar->newt = ar->oldt;
	ar->newt.c_lflag &= ~ECHO;
	ar->newt.c_lflag &= ~ICANON;
	tcsetattr(ar->tty, 0, &ar->newt);
	return (make_col(b, ac));
}

void	check_error(t_beg ar)
{
	if (ar.term == NULL)
	{
		ft_putstr_fd("environnment variable \"TERM\" not set\n", ar.tty);
		exit(0);
	}
	if (ar.tgent != 1 || ar.tty)
	{
		ft_putstr_fd("Error to initialize tgetent\n", ar.tty);
		exit(0);
	}
	if (ar.fin.col == NULL)
	{
		ft_putstr_fd("Not Enougth Argument\n", ar.tty);
		exit(0);
	}
}

void	start(char **b, int ac)
{
	t_beg	ar;

	if (*b == NULL)
		return ;
	ar.fin.col = ft_beg(&ar, b, ac);
	ar.tmp.col = NULL;
	check_error(ar);
	ar.tmp.index = 1;
	begin(&ar);
	ft_libere(&ar);
}

int		main(int ac, char **av)
{
	if (ac-- > 1)
	{
		if (!(isatty(STDERR_FILENO)))
			return (0);
		grab_sign();
		av++;
		start(av, ac);
	}
	else
		ft_putstr("Not Enougth Argument\n");
	return (0);
}
