/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit_frealloc.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpollich <cpollich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/17 21:57:36 by cpollich          #+#    #+#             */
/*   Updated: 2019/04/17 21:57:49 by cpollich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	**intalloc(void)
{
	int	**array;
	int i;
	int j;

	array = (int **)malloc(4 * sizeof(int *));
	if (!array)
		return (NULL);
	i = 0;
	while (i < 4)
	{
		if (!(array[i] = (int *)malloc(4 * sizeof(int))))
		{
			j = 0;
			while (j < i)
				free(array[j++]);
			return (0);
		}
	}
	return (array);
}

int	rm_intallocmem(int **ar)
{
	int i;

	i = 0;
	while (i < 4)
	{
		free(ar[i]);
		ar[i] = 0;
	}
	free(ar);
	ar = 0;
	return (0);
}
