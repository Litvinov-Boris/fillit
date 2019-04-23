/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpollich <cpollich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/21 19:16:52 by cpollich          #+#    #+#             */
/*   Updated: 2019/04/22 21:44:31 by cpollich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>

char		*zeromap(int size)
{
	char	*map;
	int		x;
	int		y;

	if ((map = (char*)malloc(sizeof(char) * (size + 1) * (size))) != NULL)
	{
		y = 0;
		while (y < size)
		{
			x = 0;
			while (x <= size)
			{
				if (x != size)
					map[y * (size + 1) + x] = '.';
				else
					map[y * (size + 1) + x] = '\n';
				x++;
			}
			y++;
		}
	}
	return (map);
}

int			printmap(t_tetrim *list, int size)
{
	char	*map;
	int		x;
	int		y;

	if (!(map = zeromap(size)))
		return (0);
	while (list != NULL)
	{
		y = 0;
		while (y < list->height)
		{
			x = 0;
			while (x < list->width)
			{
				if (list->form >> (16 * (y + 1) - 1 - x) & 1)
					map[(list->y + y) * (size + 1) + x + list->x] = list->id;
				x++;
			}
			y++;
		}
		list = list->next;
	}
	ft_putstr(map);
	free(map);
	return (1);
}

int			printerror(t_tetrim **list)
{
	ft_putstr("error");
	clear_list(list);
	return (0);
}

int			main(int ac, char **av)
{
	int			fd;
	t_tetrim	*list;
	uint16_t	map[16];
	int			count;

	if (ac != 2)
		ft_putstr("usage: ./fillit [filename]\n");
	else
	{
		list = NULL;
		fd = open(av[1], O_RDONLY);
		if (!(count = list_t(fd, &list, 0)))
			return (printerror(&list));
		ft_bzero(map, sizeof(uint16_t) * 16);
		if (!(count = bruteforce(count, map, list)))
			return (printerror(&list));
		if (printmap(list, count))
			clear_list(&list);
		else
			return (printerror(&list));
	}
	return (0);
}
