/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_enter.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bordenoy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/22 16:22:50 by bordenoy          #+#    #+#             */
/*   Updated: 2019/04/24 19:19:07 by bordenoy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

static int	get_f(t_beg *b)
{
	int i;
	int g;

	g = 0;
	i = 0;
	while (i < b->fin.col_size)
	{
		if (b->fin.col[i].choice == 1 && b->fin.col[i].live == 1)
			g += ft_strlen(b->fin.col[i].name) + 1;
		i++;
	}
	return (g);
}

static char	*enterf(t_beg *g)
{
	char	*t;
	int		i;
	int		u;
	int		c;

	i = 0;
	t = NULL;
	u = 0;
	if (!get_f(g) || !(t = (char *)malloc(sizeof(char) * (get_f(g)))))
		return (NULL);
	while (i < g->fin.col_size)
	{
		c = 0;
		if (g->fin.col[i].choice == 1 && g->fin.col[i].live == 1)
		{
			if (u)
				t[u++] = ' ';
			while (g->fin.col[i].name[c])
				t[u++] = g->fin.col[i].name[c++];
		}
		i++;
	}
	t[u] = '\0';
	return (t);
}

void		enter(t_beg *g)
{
	char	*t;

	if (g->mod == 1)
	{
		t = enterf(g);
		ft_putstr_fd(tgetstr("me", NULL), 0);
		ft_putstr_fd(g->cap[3].name, 0);
		ft_libere(g);
		if (t)
			ft_putstr(t);
		if (t)
			free(t);
		exit(0);
	}
}
