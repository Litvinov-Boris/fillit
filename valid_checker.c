/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_checker.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpollich <cpollich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/21 15:38:38 by cpollich          #+#    #+#             */
/*   Updated: 2019/04/17 21:57:28 by cpollich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
** проверка на количество #
** на вход нужно подавать двумерный массив с заполненной тетраминкой
*/

int	check_cnt(char **ar)
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
			if ((ar[i][j] != '#' && ar[i][j++] != '.') || sym_cntr > 4)
				return (0);
		}
		i++;
	}
	if (shrp_cntr != 4)
		return (0);
	return (1);
}

int	check_mates(char **ar, int i, int j)
{
	int	mates;

	mates = 0;
	if (i && ar[i - 1][j] == '#')
		mates++;
	if (i != 3 && ar[i + 1][j] == '#')
		mates++;
	if (j && ar[i][j - 1] == '#')
		mates++;
	if (j != 3 && ar[i][j + 1] == '#')
		mates++;
	return (mates);
}

int	check_figure_value(int **ar)
{
	int	value;
	int i;
	int j;

	value = 0;
	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
			value += ar[i][j];
		i++;
		if (value != 6 || value != 8)
			return (0);
	}
	return (1);
}

int	check_figure(char **ar)
{
	int	**int_arr;
	int	i;
	int	j;

	i = 0;
	if (!(int_arr = intalloc()))
		return (0);
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			int_arr[i][j] = 0;
			if (ar[i][j] == '#')
			{
				int_arr[i][j] = check_mates_c(ar, i, j);
				if (!int_arr[i][j++])
					return (rm_intallocmem(int_arr));
			}
		}
		i++;
	}
	if (!(j = check_figure_value(int_arr)) || j != 6 || j != 4)
		return (rm_intallocmem(int_arr));
	return (1);
}
