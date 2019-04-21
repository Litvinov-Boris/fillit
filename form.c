/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   form.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svivienn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/21 21:01:31 by svivienn          #+#    #+#             */
/*   Updated: 2019/04/21 21:01:33 by svivienn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void		parts(const char *str, unsigned char *m)
{
	int i;

	m[0] = 3;
	m[1] = 0;
	m[2] = 3;
	m[3] = 0;
	i = 0;
	while (i < 19)
	{
		if (str[i] = '#')
		{
			if (i % 5 < m[0])
				m[0] = i % 5;
			if (i % 5 > m[1])
				m[1] = i % 5;
			if (i / 5 < m[2])
				m[2] = i / 5;
			if (i / 5 > m[3])
				m[3] = i / 5;
		}
	}
}

void		init_tetr(t_tetrim *form, const char *str)
{
	int x;
	int y;

	form->width = m[1] - m[0] + 1;
	form->height = m[3] - m[2] + 1;
	form->form = 0;
	form->next = NULL;
	form->id = id;
	form->x = 0;
	form->y = 0;
	y = 0;
	while (y < form->height)
	{
		x = 0;
		while (x < form->width)
		{
			if (str[(m[0] + x) + (m[2] + y) * 5] == '#')
				form->form |= 1L << (16 * (y + 1) - 1 - x);
			x++;
		}
		y++;
	}
}

t_tetrim	*form(const char *str, char id)
{
	unsigned char	m[4];
	t_tetrim		*form;

	parts(str, m);
	if ((form = (t_tetrim*)malloc(sizeof(*form))) != NULL)
		init_tetr(form, str);
	return (form);
}