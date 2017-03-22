# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abourgeu <abourgeu@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/24 11:37:19 by abourgeu          #+#    #+#              #
#    Updated: 2017/03/22 12:18:57 by abourgeu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol

CFLAGS = -Wall -Wextra -Werror

SRC = 	srcs/main.c srcs/key_code.c srcs/algo_draw.c srcs/ft_init_env.c		\
		srcs/ft_mouse.c 													\

OBJ = $(SRC:.c=.o)

$(NAME): $(OBJ)
	make -C ./libft
	make -C ./minilibx
	@gcc $(CFLAGS) -o $(NAME) -framework OpenGL -framework AppKit \
	minilibx/libmlx.a -lft -L./libft -I./libft $(OBJ)
	@echo "Fractol compiled."

all: $(NAME)

clean:
	make -C ./libft clean
	make -C ./minilibx clean
	rm -rf $(OBJ)

fclean : clean
	make -C ./libft fclean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean make fclean re
