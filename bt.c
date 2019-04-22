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
	if (!list)
		return (1);
	while (list->y <= (size - list->height))
	{
		list->x = 0;
		while (list->x <= (size - list->width))
		{
			if (check_point(map, list))
			{
				busy_map(map, list);
				if (backtrack(map, list->next, size))
					return (1);
				busy_map(map, list);
			}
			list->x++;
		}
		list->y++;
	}
	list->x = 0;
	list->y = 0;
	return (0);
}

int		check_point(uint16_t *map, t_tetrim *list)
{
	if(*(uint64_t*)(map + list->y) & (list->form >> list->x))
		return (0);
	return (1);
}

void	busy_map(uint16_t *map, t_tetrim *list)
{
	*(uint64_t*)(map + list->y) ^= list->form >> list->x;
}