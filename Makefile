# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: maxim <maxim@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/07/12 00:28:37 by maxim             #+#    #+#              #
#    Updated: 2020/07/23 23:56:10 by maxim            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

FLAGS =

OBJ_DIR = obj/
SRC_DIR = src/

INCLUDES = -I $(MLX_DIR) -I $(LIBFT_DIR)includes -Iincludes

LIBFT_DIR = libft/
LIBFT_NAME = libft.a
LIBFT = -L$(LIBFT_DIR) -lft

MLX_DIR = minilibx/
LIB_MLX = -L$(MLX_DIR) -lmlx -L/usr/include -lXext -lX11 -lm -lbsd

SRC_FILES = main.c		\
			read_map.c	\
			draw_line.c	\
			draw_map.c	\
			matrix.c	\
			handle_keys_and_mouse.c

SRCS = $(addprefix $(SRC_DIR, $(SRC_FILES)))
OBJS = $(addprefix $(OBJ_DIR), $(SRC_FILES:.c=.o))

all: $(NAME)

$(NAME): $(OBJ_DIR) $(OBJS) $(LIBFT_DIR)$(LIBFT_NAME)
	gcc $(FLAGS) -o $(NAME) $(OBJS) $(LIB_MLX) $(LIBFT)

$(OBJ_DIR):
	mkdir $(OBJ_DIR)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	gcc $(FLAGS) $(INCLUDES) -o $@ -c $<

$(LIBFT_DIR)$(LIBFT_NAME):
	make -C $(LIBFT_DIR)
clean:
	rm -rf $(OBJ_DIR)
	make -C $(LIBFT_DIR) clean

fclean: clean
	rm $(NAME)
	make -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all fclean clean re