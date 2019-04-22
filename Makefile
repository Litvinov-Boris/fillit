# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cpollich <cpollich@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/03/21 19:05:00 by cpollich          #+#    #+#              #
#    Updated: 2019/04/22 18:49:05 by cpollich         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

F = -Wall -Wextra -Werror

SRCS =	valid_checker.c \
		form.c \
		main.c

SRCO = $(SRCS:.c=.o)

INCLUDES = fillit.h

LIBFT = libft/libft.a

all: $(NAME)

$(LIBFT): 
	make -C libft

$(SRCO): %.o: %.c
	gcc $F -g -c $< -I. -o $@

$(NAME): $(LIBFT) $(SRCO)
	gcc $F -g $(SRCO) -o $(NAME) $(LIBFT)

clean:
	rm -f $(SRCO)
	make -C libft clean

fclean: clean
	rm -f $(NAME)
	make -C LIBFT fclean

re: fclean all
