NAME		= 		fdf
SRC			= 		main.c \
					bresenham.c \
					render.c \
					events.c \
					file.c \
					instance.c \
					map.c \
					color.c \
					rotate.c \
					interaction.c \
					utils.c

LIBFT		= 		./libft/libft.a
SRCS_PATH	= 		src
OBJS_PATH	= 		obj
SRCS		= 		$(addprefix $(SRCS_PATH)/, $(SRC))
OBJS		= 		$(addprefix $(OBJS_PATH)/, $(SRC:.c=.o))

CC			= 		cc -Wall -Wextra -Werror -g
MLX			= 		-lmlx -lXext -lX11 -lm 
RM			= 		rm -rf

all: $(NAME)

$(NAME):			$(OBJS_PATH) $(LIBFT) $(OBJS)
					$(CC) $(OBJS) $(LIBFT) $(MLX) -o $(NAME)
#valgrind --leak-check=full --show-leak-kinds=all --tool=memcheck --show-reachable=yes --track-origins=yes ./fdf test_maps/t1.fdf
					

$(OBJS_PATH):
					mkdir -p $(OBJS_PATH)

$(OBJS_PATH)/%.o:	$(SRCS_PATH)/%.c
					$(CC) -c $< -o $@

$(LIBFT):
					make -C ./libft

test:				$(NAME)
					./fdf test_maps/42.fdf

clean:
					$(RM) $(OBJS_PATH)

fclean:				clean
					make fclean -C ./libft
					$(RM) $(NAME)

re:					fclean all

.PHONY:				all clean fclean re
























