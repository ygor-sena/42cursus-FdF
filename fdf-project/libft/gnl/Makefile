NAME		= ../libft.a

SRC			= get_next_line_bonus.c get_next_line_utils_bonus.c
GNL_OBJ	= $(SRC:.c=.o)

all:		$(NAME)

$(NAME): $(GNL_OBJ)

%.o: %.c
	$(CC) -c $< -o $@
	ar -rcs $(NAME) $@

clean:
	$(RM) $(GNL_OBJ)

fclean:		clean

re:			fclean all
			$(RM) $(NAME)

.PHONY:		all clean fclean re