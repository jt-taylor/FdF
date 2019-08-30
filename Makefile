# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jtaylor <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/16 19:30:49 by jtaylor           #+#    #+#              #
#    Updated: 2019/08/29 16:48:16 by jtaylor          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

FLAGS = -Wall -Wextra -Werror -I ./libft/includes

DEBUG_FLAG = -g3

LINKED_LIB = -L ./minilibx_macos -l mlx 
#"-lXext -lX11"

FRAMEWORK = -framework OpenGL -framework AppKit

MINILIBX_HEADER_PATH = ./minilibx_macos/

INCLUDES = -I ./libft/includes
INCLUDES += -I ./includes
INCLUDES += -I $(MINILIBX_HEADER_PATH)

SRC = main.c


.PHONY = all clean fclean re

all : $(NAME)

$(NAME) :
	@make -C ./libft
	@make -C ./minilibx_macos
	@echo "\tBuilding $(NAME) executable\n"
	gcc $(FLAGS) $(SRC) $(FRAMEWORK) $(LINKED_LIB) $(INCLUDES) ./libft/libft.a ./libft/ft_printf/libftprintf.a -o $(NAME)

debug :
	@make debug -C ./libft
	@echo "\tBuilding $(NAME) debug executable\n"
	@gcc $(FLAGS) $(SRC) $(DEBUG_FLAG) -ltermcap -I ./includes ./libft/libft.a ./libft/ft_printf/libftprintf.a -o $(NAME)

clean :
	@make -C libft clean

fclean : clean
	@echo "\tRemoving $(NAME) Executable\n"
	@rm -rf $(NAME)
	@rm -rf $(NAME).dSYM
	@make -C libft fclean

re : fclean all

r :
	rm $(NAME);
	make all
