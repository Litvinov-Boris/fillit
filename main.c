/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpollich <cpollich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/21 19:16:52 by cpollich          #+#    #+#             */
/*   Updated: 2019/04/22 19:13:49 by cpollich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

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
		if (!(count = list_t(fd, &list)))
		{
			ft_putstr("error");
			clear_list(&list);
			return (0);
		}
		ft_bzero(map, sizeof(uint16_t) * 16);
		printf("%i\n", bruteforse(count, map, list);
	}
	return (0);
}
