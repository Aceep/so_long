# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aceep <aceep@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/04 15:45:50 by alycgaut          #+#    #+#              #
#    Updated: 2023/06/01 23:53:19 by aceep            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#Project Name
NAME = so_long

#Compiler
CC = clang

#Remove
RM = rm -rf

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

#Librairies
LIB_DIR = ./libft
LIBFT = $(LIB_DIR)/libft.a
LDFLAGS = -L $(LIB_DIR) -lft

#Mlx
MLX_DIR = ./mlx_linux
MLX = $(MLX_DIR)/libmlx.a
MLX_FLAGS  = -L $(MLX_DIR) -lmlx -L/usr/lib -lXext -lX11 -lm -lz

#Includes
INC_DIR = ./includes
INCLUDES += -I $(LIB_DIR)/includes
INCLUDES += -I $(INC_DIR)
INCLUDES += -I $(MLX_DIR)

#Headers
HEARDERS += start.h
HEARDERS += so_long.h
vpath %.h $(INC_DIR)

#Source Directories
CORE_DIR = ./core
ERR_DIR = ./error
FREE_DIR = ./free

#Sources
SRCS += main.c
SRCS += check_map.c
SRCS += error_struct.c
SRCS += create_map.c
SRCS += free.c
SRCS += free2.c
SRCS += init_player.c
SRCS += play.c
SRCS += move.c
SRCS += exit_game.c
SRCS += xpm_main.c
SRCS += check_path.c
SRCS += enemy.c
SRCS += enemy_patrol.c
SRCS += generate_map.c
SRCS += big_bang.c
SRCS += error_image.c

#Vpath Source
vpath %.c $(CORE_DIR)
vpath %.c $(ERR_DIR)
vpath %.c $(FREE_DIR)

#Objects
OBJS_DIR = ./objs
OBJS = $(patsubst %.c, $(OBJS_DIR)/%.o, $(SRCS))

#Counter
TOTAL = $(words $(SRCS))
COUNT = 0

#PATROL MOVES
PATROL = 0

#Rules
all : $(NAME)

mega :
	@./mega

$(NAME): $(MLX) $(LIBFT) $(OBJS)
	@$(CC) $^ $(LDFLAGS) $(MLX_FLAGS) $(INCLUDES) -o $@
	@make --no-print-directory -C ./start
	@echo -n "$(BYELLOW)So_long is ready ! ->\n$(NC)"

$(OBJS) : $(OBJS_DIR)/%.o: %.c | $(LIBFT) $(OBJS_DIR)
	@$(CC) $(INCLUDES) -c $< -o $@
	@if [ $(COUNT) = 0 ]; then echo ""; fi
	@$(eval COUNT=$(shell echo $$(($(COUNT)+1))))
	@$(eval PERCENT:=$(shell echo $$((100*$(COUNT)/$(TOTAL)))))
	@printf "$(OL)$(BCYAN)[%2d/%2d] %3d%%\tCompiling %s$(NC)\n" $(COUNT) $(TOTAL) $(PERCENT) $<

$(LIBFT):
	@make --no-print-directory -C $(LIB_DIR)
	@printf "$(BGREEN)Libft compiled$(NC)\n"

$(MLX):
	@make -s -C $(MLX_DIR)
	@printf "$(BGREEN)Mlx compiled$(NC)\n"

$(OBJS_DIR):
	@mkdir $(OBJS_DIR)

clean : $(OBJS)
	@$(RM) $(OBJS_DIR)
	@$(RM) start/objs

fclean : clean
	@$(RM) $(LIBFT)
	@$(RM) $(MLX)
	@$(RM) $(NAME)
	@$(RM) start/start

lclean :
	@make --no-print-directory clean -C $(LIB_DIR)
	@make --no-print-directory clean -sC $(MLX_DIR)

re : fclean 
	@make --no-print-directory all

norme :
	norminette core/
	norminette error/
	norminette free/
	norminette includes/
	norminette libft/
	norminette start/

.PHONY : mega