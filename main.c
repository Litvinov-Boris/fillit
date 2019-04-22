/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpollich <cpollich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/21 19:16:52 by cpollich          #+#    #+#             */
/*   Updated: 2019/04/22 16:49:09 by cpollich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int			main(int ac, char **av)
{
	int		fd;
	char	**figure;

	if (ac != 2)
		ft_putstr("usage: ./fillit [filename]\n");
	else
	{
		fd = open(av[1], O_RDONLY);
	}
	return (0);
}
