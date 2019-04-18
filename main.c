/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bordenoy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/15 11:19:34 by bordenoy          #+#    #+#             */
/*   Updated: 2019/04/18 02:31:33 by bordenoy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

t_beg	g_beg;

t_col	*make_col(char **b, int ac)
{
	t_col	*p;
	int		i;

	i = 0;
	if (!(p = (t_col *)malloc(sizeof(t_col) * ac)))
		return (NULL);
	while (b[i])
	{
		p[i].live = 1;
		p[i].len = ft_strlen(b[i]);
		p[i].name = ft_strdup(b[i]);
		i++;
	}
	return (p);
}

t_col	*ft_beg(t_beg *ar, char **b, int ac)
{
	ar->tgent = 0;
	ar->col = NULL;
	ar->col_size = ac;
	ar->col_nbr = ac;
	tcgetattr(STDERR_FILENO, &ar->oldt);
	ar->newt = ar->oldt;
	ar->newt.c_lflag &= ~ECHO;
	ar->newt.c_lflag &= ~ICANON;
	tcsetattr(STDERR_FILENO, 0, &ar->newt);
	if (!(ar->tty = open(ttyname(0), O_RDWR)))
		return (NULL);
	if (!(ar->term = getenv("TERM")))
		return (NULL);
	if ((ar->tgent = tgetent(NULL, ar->term)) != 1)
		return (NULL);
	return (make_col(b, ac));
}

void	check_error(t_beg ar)
{
	if (ar.term == NULL)
	{
		ft_putstr("environnment variable \"TERM\" not set\n");
		exit(0);
	}
	if (ar.tgent != 1)
	{
		ft_putstr("Error to initialize tgetent\n");
		exit(0);
	}
	if (ar.col == NULL)
	{
		ft_putstr("Not Enougth Place\n");
		exit(0);
	}
}

void	start(char **b, int ac)
{
	t_beg	ar;

	if (*b == NULL)
		return ;
	ar.col = ft_beg(&ar, b, ac);
	check_error(ar);
	begin(&ar);
	ft_libere(ar);
}

int		main(int ac, char **av)
{
	if (!(isatty(STDERR_FILENO)))
		return (0);
	grab_sign();
	if (ac-- > 1)
	{
		av++;
		start(av, ac);
	}
	return (0);
}
