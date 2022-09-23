NAME		= ../libft.a

OBJ			= obj

SRCS		= $(addprefix src/, $(S_FILES_BONUS))

S_FILES_BONUS	=	ft_printf_bonus.c \
					ft_instance_bonus.c \
					ft_sort_format_bonus.c \
					ft_parse_bonus.c \
					ft_type_cast_bonus.c \
					ft_cast_char_bonus.c \
					ft_cast_percent_bonus.c \
					ft_cast_string_bonus.c \
					ft_cast_pointer_bonus.c \
					ft_cast_unsigned_bonus.c \
					ft_cast_integer_bonus.c \
					ft_cast_hexa_bonus.c

SRC_OBJ		= $(subst src, obj, $(SRCS:.c=.o))

CC			= cc
CFLAGS		= -Wall -Wextra -Werror -O3
RM			= rm -rf

all:		$(NAME)

$(NAME):	$(OBJ) $(SRC_OBJ)

$(OBJ):
	mkdir -p $(OBJ)

$(OBJ)/%.o:	src/%.c
	$(CC) $(CFLAGS) -c $< -o $@
	ar -rcs $(NAME) $@

clean:
	$(RM) $(SRC_OBJ)
	$(RM) $(OBJ)

fclean:		clean
			$(RM) $(NAME)

re:			fclean all

.PHONY:		all clean fclean re