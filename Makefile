# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ahocuk <ahocuk@student.42heilbronn.de>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/10 16:26:01 by ahocuk            #+#    #+#              #
#    Updated: 2024/03/12 18:07:02 by ahocuk           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.SILENT:

SRC = main.c parser.c p_texture.c utils1.c p_color.c\

OBJ = $(SRC:.c=.o)

MLX			=	MLX42/build
MLX_LIB		=	MLX42/build/libmlx42.a
GLFW_LIB	=	 -lglfw

LIBFT		=	libft/
LIBFT_LIB	=	libft/libft.a

NAME = cub3D

CC		= 	cc
RM		=   rm -f
CFLAGS	= -Wall -Werror -Wextra 

all: $(NAME)

$(NAME): $(LIBFT_LIB) $(OBJ) $(MLX_LIB) 
	$(CC) $(CFLAGS) $(LIBFT_LIB) $(OBJ) $(MLX_LIB)  -o $(NAME) $(GLFW_LIB)
	echo "cub3D compiled successfully"

$(MLX_LIB):
	cd MLX42 && cmake -B build && cd ..
	make -C $(MLX)
	echo "MLX42 compiled successfully"

$(LIBFT_LIB):
	make bonus -C $(LIBFT) && make clean -C $(LIBFT)
	echo "LIBFT compiled successfully"

clean:
	$(RM) $(OBJ)
	$(RM) $(LIBFT_LIB)
	echo "Object-Files are cleaned!"

fclean: clean
	$(RM) $(NAME)
	echo "Programs / Libraries are cleaned!"

re: fclean all 

.PHONY: all clean fclean re