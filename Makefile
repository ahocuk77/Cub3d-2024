.SILENT:

NAME				:= cub3D

CC					:= gcc

CFLAGS				:= -Wall -Werror -Wextra
LDFLAGS				:= -flto -O3 -march=nocona
HEADERS				:=	-I ./include -I ./lib/MLX42/include/MLX42/

MAIN				:=	./00_main/main.c \
						./00_main/get_next_line.c \
						./00_main/get_next_line_utils.c \

PARSER				:=	./01_parser/parser.c \
						./01_parser/p_texture.c \
						./01_parser/utils1.c \
						./01_parser/p_color.c \
						./01_parser/p_map.c \
						./01_parser/utils2.c \
						./01_parser/utils3.c \
						./01_parser/map_check.c \
						./01_parser/horizontal_check.c \
						./01_parser/vertical_check.c \
						./01_parser/init.c \
						./01_parser/free_all.c \

RENDERER			:=	./02_renderer/00_init_player.c \
						./02_renderer/01_render.c \
						./02_renderer/02_cast_ray_00.c \
						./02_renderer/02_cast_ray_01.c \
						./02_renderer/03_hooks.c \
						./02_renderer/utils.c

SRCS				:=	$(MAIN) \
						$(PARSER) \
						$(RENDERER)

OBJ_DIR				:=	./obj/

OBJS				:=	$(addprefix $(OBJ_DIR), $(SRCS:.c=.o))

all:				$(NAME)

LIBMLX42			:=	"./lib/MLX42/libmlx42.a"
LIBGLFW				:=	"./lib/glfw-3.3.8.bin.MACOS/lib-x86_64/libglfw3.a"
FRAMEWORK			:=	-framework Cocoa -framework OpenGL -framework IOKit

LIBFT				:=	./lib/libft/
LIBFT_LIB			:=	./lib/libft/libft.a

$(NAME):			$(OBJ_DIR) $(OBJS) $(LIBFT_LIB)
	$(CC) $(OBJS) $(LDFLAGS) $(LIBFT_LIB) $(FRAMEWORK) $(LIBMLX42) $(LIBGLFW) \
	-o $(NAME) \
	&& echo "Compilation of $(NAME) is successful"

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

$(OBJ_DIR)%.o: %.c
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) $(HEADERS) -c $< -o $@

$(LIBFT_LIB):
	make bonus -C $(LIBFT) && make clean -C $(LIBFT)
	echo "LIBFT compiled successfully"

clean:
	${MAKE} -C $(LIBFT) fclean
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
