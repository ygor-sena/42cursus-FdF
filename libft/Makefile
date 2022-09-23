SRCS		= 	ft_isalpha.c ft_isdigit.c ft_toupper.c ft_tolower.c \
				ft_isalnum.c ft_isascii.c ft_isprint.c ft_strlen.c \
				ft_strchr.c ft_strrchr.c ft_strncmp.c ft_strnstr.c \
				ft_strlcat.c ft_strlcpy.c ft_memset.c ft_bzero.c \
				ft_memcpy.c ft_memmove.c ft_memchr.c ft_memcmp.c \
				ft_atoi.c ft_calloc.c ft_strdup.c ft_substr.c \
				ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c \
				ft_strmapi.c ft_striteri.c ft_putchar_fd.c \
				ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c \
				ft_utoa_base.c ft_free.c ft_atoi_base.c

SRCS_BONUS	= 	ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c \
				ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c \
				ft_lstiter.c ft_lstmap.c

CC			= 	cc
CC_FLAGS	= 	-Wall -Werror -Wextra -O3
RM			= 	rm -rf

NAME		= 	libft.a

OBJS_DIR	= obj
OBJS		= $(addprefix $(OBJS_DIR)/, $(SRCS:.c=.o))
OBJS_BONUS	= $(addprefix $(OBJS_DIR)/, $(BONUS:.c=.o))

all:		$(NAME)

$(NAME):	$(OBJS_DIR) $(OBJS) gnl ft_printf

bonus:		$(OBJS_DIR) $(OBJS) $(OBJS_BONUS) gnl ft_printf

$(OBJS_DIR):
	mkdir -p $(OBJS_DIR)

$(OBJS_DIR)/%.o:	%.c
	$(CC) $(CFLAGS) -c $< -o $@
	ar -rcs $(NAME) $@

gnl:
	make -C gnl

ft_printf:
	make -C ft_printf

clean:
	$(RM) $(OBJS) $(OBJS_BONUS) -r $(OBJS_DIR)
	make clean -C gnl
	make clean -C ft_printf

fclean:		clean
			$(RM) $(NAME)

re:			fclean all

.PHONY:		all clean fclean re bonus gnl ft_printf
