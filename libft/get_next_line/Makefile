SRCS = get_next_line_bonus.c \
		get_next_line_utils_bonus.c \

OBJS = $(SRCS:.c=.o)

HEADER = get_next_line_bonus.h \

LIBFT_PATH = ../libft

GCC = gcc 

RM = rm -rf

CFLAGS = -Wall -Wextra -Werror

NAME = gnl.a

.c.o:
	${GCC} ${CFLAGS} -c $< -o ${<:.c=.o}

$(NAME) : $(OBJS)
		make -C $(LIBFT_PATH) bonus
		cp $(LIBFT_PATH)/libft.a ./$(NAME)
		ar rcs $(NAME) $(OBJS)

all : $(NAME)

clean : 
		make -C $(LIBFT_PATH) clean
		$(RM) $(OBJS)

fclean : clean 
		make -C $(LIBFT_PATH) fclean
		$(RM) $(NAME)

re : fclean all


