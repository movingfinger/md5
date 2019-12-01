# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sako <sako@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/06/13 23:05:35 by sako              #+#    #+#              #
#    Updated: 2019/09/07 21:54:11 by sako             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

DIRHDER = ./includes/
DIRLIB = ./libft/
DIRSRC = ./srcs/

FLAG = -Wall -Wextra -Werror

all: $(NAME)

$(NAME):
	gcc -c $(DIRLIB)*.c $(DIRSRC)*.c -I $(DIRHDER) $(FLAG)
	ar rcs $(NAME) *.o

clean:
	/bin/rm -f *.o

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all
