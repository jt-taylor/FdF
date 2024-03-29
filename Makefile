# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jtaylor <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/16 19:30:49 by jtaylor           #+#    #+#              #
#    Updated: 2019/09/06 13:21:25 by jtaylor          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

FLAGS = -Wall -Wextra -Werror -I ./libft/includes

DEBUG_FLAG = -g3

FSANITIZE = -fsanitize=address -fsanitize=undefined

LINKED_LIB = -L ./minilibx_macos -l mlx
#"-lXext -lX11"

FRAMEWORK = -framework OpenGL -framework AppKit

MINILIBX_HEADER_PATH = ./minilibx_macos/
MLX_DIR = minilibx_macos

INCLUDES = -I ./libft/includes
INCLUDES += -I ./includes
INCLUDES += -I $(MINILIBX_HEADER_PATH)

SRC_FILE = main.c \
			fdf_read_input_file.c \
			draw_line.c \
			fdf_draw_img.c \
			fdf_keypress.c \
			fdf_draw_test.c
SRC = $(addprefix ./src/, $(SRC_FILE))

.PHONY = all clean fclean re

all : mlx_made $(NAME)

$(NAME) :
	@make -C ./libft
	@make -C ./minilibx_macos
	@echo "\tBuilding $(NAME) executable\n"
	gcc $(FLAGS) $(INCLUDES) $(FRAMEWORK) $(LINKED_LIB) $(SRC) ./libft/libft.a ./libft/ft_printf/libftprintf.a -o $(NAME)

debug : mlx_made
	@make debug -C ./libft
	@make -C ./minilibx_macos
	@echo "\tBuilding $(NAME) debug executable\n"
	gcc $(FLAGS) $(DEBUG_FLAG) $(INCLUDES) $(FRAMEWORK) $(LINKED_LIB) $(SRC) ./libft/libft.a ./libft/ft_printf/libftprintf.a -o $(NAME)

fsan :
	@make -C ./libft
	@make -C ./minilibx_macos
	@echo "\tBuilding $(NAME) executable\n"
	gcc $(FLAGS) $(FSANITIZE) $(SRC) $(FRAMEWORK) $(LINKED_LIB) $(INCLUDES) ./libft/libft.a ./libft/ft_printf/libftprintf.a -o $(NAME)

mlx_made :
	tar -xvf minilibx.tar

clean :
	@make -C libft clean

fclean : clean
	@echo "\tRemoving $(NAME) Executable\n"
	@rm -rf $(NAME)
	@rm -rf $(NAME).dSYM
	@make -C libft fclean
#	@make -C $(MLX_DIR) clean
	@rm -rf $(MLX_DIR)

re : fclean all

r :
	rm $(NAME);
	make all
