# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alycgaut <alycgaut@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/19 17:07:50 by alycgaut          #+#    #+#              #
#    Updated: 2023/01/10 14:11:18 by alycgaut         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS =	ft_printf.c \
		ft_format_d_i_u.c \
		ft_format_str_char.c \
    	ft_format_pointer.c \
        ft_format_hexa.c \
		check_arg.c \

OBJS = $(SRCS:.c=.o)

HEADER = ft_printf.h \

GNL_PATH = ../get_next_line

NAME = libftprintf.a

GCC = gcc -Wall -Werror -Wextra

RM = rm -rf

.c.o:
	${GCC} -c $< -o ${<:.c=.o}

$(NAME) : $(OBJS)
	make -C $(GNL_PATH)
	cp $(GNL_PATH)/gnl.a ./$(NAME)
	ar rcs $(NAME) $(OBJS)

all : $(NAME)

clean :
	make -C $(GNL_PATH) clean
	$(RM) $(OBJS)

fclean : clean
	make -C $(GNL_PATH) fclean
	$(RM) $(NAME)

re : fclean all

