# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: svivienn <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/04/03 22:07:07 by svivienn          #+#    #+#              #
#    Updated: 2019/04/03 22:07:08 by svivienn         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
SRCS = ft_*.c
HEADER = ./
FLAGC = -Wall -Wextra -Werror -std=c99
OBG = ft_*.o

all: $(NAME)

$(NAME):
	gcc $(FLAGC) -I$(HEADER) -c $(SRCS)
	ar rc $(NAME) $(OBG)
	ranlib $(NAME)

clean:
	/bin/rm -f $(OBG)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all