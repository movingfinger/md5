# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sako <sako@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/06/13 23:05:35 by sako              #+#    #+#              #
#    Updated: 2019/11/07 17:45:28 by sako             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_ssl

DIRHDER = ./includes/
DIRLIB = ./libft/
DIRSRC = ./srcs/

FLAG = -Wall -Wextra -Werror

all: $(NAME)

$(NAME):
	gcc $(FLAG) -o $(NAME) $(DIRLIB)*.c $(DIRSRC)*.c -I $(DIRHDER)

clean:
	/bin/rm -f *.o

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all
