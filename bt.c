/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bt.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svivienn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/22 18:48:10 by svivienn          #+#    #+#             */
/*   Updated: 2019/04/22 18:48:12 by svivienn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		bruteforce(int counts, uint16_t *map, t_tetrim *list)
{
	int size;

	size = 2;
	while ((size * size) < (count * 4))
		size++;
	while (!backtrack(map, list, size) && size <= 16)
	{
		ft_bzero(map, sizeof(uint16_t) * 16);
		size++;
	}
	if (size == 17)
		return (0);
	return (size);
}

int		backtrack(uint16_t *map, t_tetrim *list, int size)
{
	
}
