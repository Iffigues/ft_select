/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_jds.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bordenoy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 15:00:51 by bordenoy          #+#    #+#             */
/*   Updated: 2018/11/14 19:51:19 by bordenoy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_jds(int y, int m, int d)
{
	int dd;

	dd = -1;
	if ((y < 0) || (m < 1 || m > 12) || ((d < 0) || ft_maonthn(y, m) < d))
		return (dd);
	if (m >= 3)
	{
		dd = ((23 * m) / 9) + d + 4 + y + (y / 4) - (y / 100) + (y / 400);
		return ((dd - 2) % 7);
	}
	if (m < 3)
	{
		dd = ((23 * m) / 9) + d + 4 + y + ((y - 1) / 4);
		dd = dd - ((y - 1) / 100) + ((y - 1) / 400);
		return (dd % 7);
	}
	return (dd);
}
