# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nselaule <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/09/24 10:17:09 by nselaule          #+#    #+#              #
#    Updated: 2018/11/08 08:24:53 by nselaule         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= ft_ls

SRC		= main.c arg.c check_file.c print.c \
		  rights.c node.c sort_output.c recursion.c utils.c utils2.c \
		  report.c #pls_free_this_shit.c

OBJ		= $(SRC:.c=.o)

CFLAGS	= -Wall -Wextra -Werror -g -ggdb3

all: $(NAME)

$(NAME): $(OBJ)
	@make -C libft/ all
	@gcc $(CFLAGS) $(OBJ) -o $(NAME) -L libft/ -lft 

clean:
	@make -C libft/ clean
	@rm -rf $(OBJ)

fclean: clean
		@rm -rf $(NAME) $(OBJ)
		@make -C libft/ fclean

re: fclean $(NAME)
