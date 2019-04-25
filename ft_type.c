/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_type.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bordenoy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/22 13:17:45 by bordenoy          #+#    #+#             */
/*   Updated: 2019/04/23 14:59:00 by bordenoy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

int		ft_type(char *b)
{
	struct stat fs;

	if (lstat(b, &fs) < 0)
		return (30);
	if (S_ISLNK(fs.st_mode))
		return (3);
	if (S_ISDIR(fs.st_mode))
		return (5);
	if (fs.st_mode & S_IXUSR)
		return (8);
	if (S_ISREG(fs.st_mode))
		return (1);
	return (30);
}
