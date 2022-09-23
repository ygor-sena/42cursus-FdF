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

CC			= 		cc -Wall -Wextra -Werror -O3
MLX			= 		-lmlx -lXext -lX11 -lm 
RM			= 		rm -rf

all: $(NAME)

$(NAME):			$(OBJS_PATH) $(LIBFT) $(OBJS)
					$(CC) $(OBJS) $(LIBFT) $(MLX) -o $(NAME)
					
$(OBJS_PATH):
					mkdir -p $(OBJS_PATH)

$(OBJS_PATH)/%.o:	$(SRCS_PATH)/%.c
					$(CC) -c $< -o $@

$(LIBFT):
					make -C ./libft

1:					$(NAME)
					valgrind ./fdf maps/42.fdf

2:					$(NAME)
					valgrind ./fdf maps/10-2.fdf

3:					$(NAME)
					valgrind ./fdf maps/10-70.fdf

4:					$(NAME)
					valgrind ./fdf maps/20-60.fdf

5:					$(NAME)
					valgrind ./fdf maps/50-4.fdf

6:					$(NAME)
					valgrind ./fdf maps/100-6.fdf

7:					$(NAME)
					valgrind ./fdf maps/basictest.fdf

8:					$(NAME)
					valgrind ./fdf maps/elem-col.fdf	

9:					$(NAME)
					./fdf maps/elem-fract.fdf

10:					$(NAME)
					valgrind ./fdf maps/elem.fdf	

11:					$(NAME)
					valgrind ./fdf maps/elem2.fdf

12:					$(NAME)
					./fdf maps/julia.fdf

13:					$(NAME)
					valgrind ./fdf maps/mars.fdf

14:					$(NAME)
					valgrind ./fdf maps/pentenegpos.fdf	
				
15:					$(NAME)
					valgrind ./fdf maps/plat.fdf	

16:					$(NAME)
					valgrind ./fdf maps/pnp_flat.fdf		

17:					$(NAME)
					valgrind ./fdf maps/pylone.fdf	

18:					$(NAME)
					valgrind ./fdf maps/pyra.fdf

19:					$(NAME)
					valgrind ./fdf maps/pyramide.fdf		
				
20:					$(NAME)
					./fdf maps/t1.fdf	
					
21:					$(NAME)
					./fdf maps/t2.fdf	

clean:
					$(RM) $(OBJS_PATH)

fclean:				clean
					make fclean -C ./libft
					$(RM) $(NAME)

re:					fclean all

.PHONY:				all clean fclean re
























