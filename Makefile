# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sako <sako@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/06/13 23:05:35 by sako              #+#    #+#              #
#    Updated: 2019/12/01 11:53:10 by sako             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_ssl

DIRHDER = ./includes/
DIRHDERFTPRINTF = ./ft_printf/includes/
DIRLIB = ./libft/
DIRSRCFTPRINTF = ./ft_printf/srcs/
DIRSRC = ./srcs/

FLAG = -g  -Wall -Wextra -Werror

all: $(NAME)

$(NAME):
	gcc $(FLAG) -o $(NAME) $(DIRLIB)*.c $(DIRSRC)*.c $(DIRSRCFTPRINTF)*.c -I $(DIRHDER) -I $(DIRHDERFTPRINTF) 

clean:
	/bin/rm -f *.o

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all
