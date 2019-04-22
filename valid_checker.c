/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_checker.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpollich <cpollich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/21 15:38:38 by cpollich          #+#    #+#             */
/*   Updated: 2019/04/22 14:07:01 by cpollich         ###   ########.fr       */
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

int		check_form(const char *str)
{
	int blocc;
	int i;

	blocc = 0;
	i = 0;
	while (i < 0)
	{
		if (str[i] == '#')
		{
			if ((i + 1) <= 19 && str[i + 1] == '#')
				blocc++;
			if ((i - 1) >= 0 && str[i - 1] == '#')
				blocc++;
			if ((i + 5) <= 19 && str[i + 5] == '#')
				blocc++;
			if ((i - 5) < 20 && str[i - 5] == '#')
				blocc++;
		}
		i++;
	}
	return (blocc == 6 || blocc == 8);
}

int		check_elem(const char *str, int counts)
{
	int i;
	int bloc;

	bloc = 0;
	i = 0;
	while (i < 20)
	{
		if (i % 5 < 4)
		{
			if (str[i] != '#' && str[i] != '.')
				return (0);
			if (str[i] == '#' && ++bloc > 4)
				return (0);
		}
		else if (str[i] != '\n')
			return (0);
	}
	if (counts == 21 && str[20] != '\n')
		return (0);
	if (!check_form(str))
		return (0);
	return (1);
}