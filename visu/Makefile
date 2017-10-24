# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amazurie <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/05 13:11:07 by amazurie          #+#    #+#              #
#    Updated: 2017/08/22 15:22:38 by amazurie         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = visufiller

CC = gcc

CFLAGS = -Wall -Wextra -Werror

DFLAGS = -MMD

INC_PATH = includes
SRC_PATH = srcs
LIB_PATH = ../libft
REQ = -lft -lmlx
MLX_PATH = minilibx_macos
FW = -framework OpenGL -framework AppKit
LIB_INC_PATH = $(LIB_PATH)/includes
LIB = $(LIB_PATH)/libft.a
MLX = $(MLX_PATH)/libmlx.a

SRC =	$(SRC_PATH)/visu.c			\
		$(SRC_PATH)/read.c			\
		$(SRC_PATH)/render.c		\
		$(SRC_PATH)/render_back.c	\
		$(SRC_PATH)/render_score.c	\
		$(SRC_PATH)/parse.c			\
		$(SRC_PATH)/extra.c

OSRC = $(SRC:.c=.o)

DEPS := $(SRC:.c=.d)

NO_COLOR = \x1b[0m
OK_COLOR = \x1b[32;01m
DEL_COLOR = \x1b[33m

all: $(NAME)

$(NAME): $(LIB) $(MLX) $(OSRC)
	@echo "Compiling..."
	@$(CC) $(CFLAGS) $(OSRC) $(FW) -o $@ $(LIB) $(MLX)
	@echo "$(OK_COLOR)$@ compiled.$(NO_COLOR)"

$(LIB):
	@make -C $(LIB_PATH)

$(MLX):
	@make -C $(MLX_PATH)

%.o: %.c
	@$(CC) $(CFLAGS) $(DFLAGS) -I $(LIB_INC_PATH) -I $(INC_PATH) -I $(MLX_PATH) -c $< -o $@

clean:
	@/bin/rm -f $(OSRC)
	@/bin/rm -f $(DEPS)
	@echo "$(DEL_COLOR)Cleaning visu temporary files.$(NO_COLOR)"

fclean: clean
	@/bin/rm -f $(NAME)
	@echo "$(DEL_COLOR)Delete $(NAME) file.$(NO_COLOR)"

re: fclean all

.PHONY: all clean fclean re

-include $(DEPS)
