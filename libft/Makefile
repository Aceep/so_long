NAME = libft.a

# Reset
NC = \033[0m

# Colors
BYELLOW = \033[1;33m
BGREEN = \033[1;32m
BBLUE = \033[1;34m
BRED = \033[1;31m
BPURPLE = \033[1;35m
BCYAN = \033[1;36m
BBLACK = \033[1;30m
BWHITE = \033[1;37m

# One Line Output
OL =\e[1A\r\033[K

INC_DIR = ./includes
INCLUDES += -I $(INC_DIR)

HEADERS = ft_printf.h \
		get_next_line.h \
		libft.h 

vpath %.h $(INC_DIR)

PATH_LIBFT = ./libft
PATH_GNL = ./get_next_line
PATH_PRINTF = ./ft_printf

#Counter
TOTAL = $(words $(SRCS))
COUNT = 0

SRCS = ft_printf.c \
	ft_format_d_i_u.c \
	ft_format_str_char.c \
	ft_format_pointer.c \
	ft_format_hexa.c \
	check_arg.c \
	get_next_line.c \
	get_next_line_utils.c \
	ft_isalpha.c \
	ft_isdigit.c \
	ft_isalnum.c \
	ft_isascii.c \
	ft_isprint.c \
	ft_strlen.c \
	ft_memset.c \
	ft_bzero.c \
	ft_memcpy.c \
	ft_memmove.c \
	ft_strlcpy.c \
	ft_strlcat.c \
	ft_toupper.c \
	ft_tolower.c \
	ft_strchr.c \
	ft_strrchr.c \
	ft_strncmp.c \
	ft_memchr.c \
	ft_memcmp.c \
	ft_strnstr.c \
	ft_atoi.c \
	ft_calloc.c \
	ft_strdup.c \
	ft_substr.c \
	ft_strjoin.c \
	ft_strtrim.c \
	ft_split.c \
	ft_itoa.c \
	ft_strmapi.c \
	ft_striteri.c \
	ft_putchar_fd.c \
	ft_putstr_fd.c \
	ft_putendl_fd.c \
	ft_putnbr_fd.c \
	ft_lstnew.c \
	ft_lstadd_front.c \
	ft_lstsize.c \
	ft_lstlast.c\
	ft_lstadd_back.c \
	ft_lstdelone.c \
	ft_lstclear.c \
	ft_lstiter.c \
	ft_lstmap.c \
	ft_putstr_bonus.c \
	ft_tolowercase_bonus.c \
	ft_touppercase_bonus.c \
	ft_nbrlen_bonus.c \
	ft_memalloc_bonus.c \
	ft_putchar_bonus.c \
	ft_strcmp_bonus.c \
	ft_memccpy_bonus.c \
	ft_itoa_base.c \
	ft_ischarset.c \

vpath %.c $(PATH_LIBFT)
vpath %.c $(PATH_GNL)
vpath %.c $(PATH_PRINTF)

OBJS_DIR = ./objs
OBJS = $(patsubst %.c, $(OBJS_DIR)/%.o, $(SRCS))

CC = cc
CFLAGS = -Wall -Wextra -Werror

RM = rm -rf

all: $(OBJS_DIR) $(NAME)

$(NAME): $(OBJS) 
	@ar rcs $@ $^

$(OBJS): $(OBJS_DIR)/%.o: %.c
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@
	@if [ $(COUNT) = 0 ]; then echo ""; fi
	@$(eval COUNT=$(shell echo $$(($(COUNT)+1))))
	@$(eval PERCENT:=$(shell echo $$((100*$(COUNT)/$(TOTAL)))))
	@printf "$(OL)$(BCYAN)[%2d/%2d] %3d%%\tCompiling %s$(NC)\n" $(COUNT) $(TOTAL) $(PERCENT) $<

$(OBJS_DIR):
	@mkdir $@

clean:
	@$(RM) $(OBJS_DIR)

fclean: clean
	@$(RM) $(NAME)

re: fclean all