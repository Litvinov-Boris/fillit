/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   figure_parcer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpollich <cpollich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/21 17:58:25 by cpollich          #+#    #+#             */
/*   Updated: 2019/04/17 19:25:15 by cpollich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	**take_one_from_file(int fd)
{
	char	buf[BUFF_SIZE];
	char	**ar;
	int		ret;

	ret = read(fd, buf, BUFF_SIZE);
	if (ret == 20 || ret == 21)
	{
		ar = ft_strsplit((char *)buf, '\n');
		return (ar ? ar : NULL);
	}
	return (NULL);
}
