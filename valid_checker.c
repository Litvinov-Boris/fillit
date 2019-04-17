/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_checker.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpollich <cpollich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/21 15:38:38 by cpollich          #+#    #+#             */
/*   Updated: 2019/04/17 19:47:55 by cpollich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
** проверка на количество # и на каоличество символов в строке
** на вход нужно подавать двумерный массив с заполненной тетраминкой
*/

int		check_cnt(char **ar)
{
	int	i;
	int	j;
	int	shrp_cntr;
	int	sym_cntr;

	i = 0;
	shrp_cntr = 0;
	sym_cntr = 0;
	while (ar[i])
	{
		j = 0;
		sym_cntr++;
		while (ar[i][j])
		{
			sym_cntr++;
			if (ar[i][j] == '#')
				shrp_cntr++;
			if ((ar[i][j] != '#' && ar[i][j] != '.') || sym_cntr > 4)
				return (0);
			j++;
		}
		i++;
	}
	if (shrp_cntr != 4)
		return (0);
	return (1);
}
