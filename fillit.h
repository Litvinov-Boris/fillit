/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpollich <cpollich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/21 18:42:28 by cpollich          #+#    #+#             */
/*   Updated: 2019/04/22 14:04:13 by cpollich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#	ifndef FILLIT_H
#	define FILLIT_H

#include <fcntl.h>
#include <sys/types.h>
#include <sys/uio.h>
#include "libft/libft.h"
#include <stdint.h>

typedef struct		s_tetrim
{
	uint64_t		form;
	struct s_tetrim	*next;
	unsigned char	id;
	unsigned char	width;
	unsigned char	height;
	unsigned char	x;
	unsigned char	y;
}					t_tetrim;

int					check_cnt(char **ar);
int					check_pic(char **ar);
char				**take_one_from_file(int fd);
void				parts(const char *str, unsigned char *m);
void				init_tetr(t_tetrim *form, const char *str);
t_tetrim			*form(const char *str, char id);
int					check_form(const char *str);
int					check_elem(const char *str, int counts);
void				put_in_list(t_tetrim **list, t_tetrim *elem);
void				clear_list(t_tetrim **list);
int					list_t(int fd, t_tetrim *list);

#	endif
