NAME := fdf

CC := gcc

CFLAGS = -Wall -Werror -Wextra -g
LDFLAGS = -flto -O3 -march=nocona -g

SRC_DIR	=	./src/

SRC		:=	check.c \
			draw_utils.c \
			draw.c \
			get_next_line_utils.c \
			get_next_line.c \
			hook_fts.c \
			init_params.c \
			main.c \
			parallel_projection.c \
			read_file.c \
			rotations.c

HEADER = -I ./include -I ./lib/MLX42/include/MLX42/ -I ../LeakSanitizer 

LIBMLX42 = "./lib/MLX42/libmlx42.a"

LIBGLFW = "./lib/glfw-3.3.8.bin.MACOS/lib-x86_64/libglfw3.a"

LIBFT_PRINTF_DIR = ./lib/ft_printf
LIBFT_PRINTF = ./lib/ft_printf/libftprintf.a

FRAMEWORK = -framework Cocoa -framework OpenGL -framework IOKit

all: libft_printf
	${MAKE} $(NAME) -j

libft_printf:
	${MAKE} -C $(LIBFT_PRINTF_DIR) -j

$(NAME):
	$(CC) $(LDFLAGS) $(addprefix $(SRC_DIR),$(SRC)) $(HEADER) $(LIBMLX42) $(LIBGLFW) $(LIBFT_PRINTF) $(FRAMEWORK) \
	-o $(NAME)
# $(CC) $(LDFLAGS) $(addprefix $(SRC_DIR),$(SRC)) $(HEADER) $(LIBMLX42) $(LIBGLFW) $(LIBFT_PRINTF) $(FRAMEWORK) \
	-o $(NAME) -L ../LeakSanitizer -llsan -lc++ -Wno-gnu-include-next

clean:
	${MAKE} -C $(LIBFT_PRINTF_DIR) fclean

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
