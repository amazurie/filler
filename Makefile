# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jmoucade <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/05 13:11:07 by jmoucade          #+#    #+#              #
#    Updated: 2017/08/22 15:22:38 by amazurie         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = amazurie.filler

VISU = visufiller

CC = gcc

DFLAGS = -MMD

CFLAGS = -Wall -Wextra -Werror

INC_PATH = includes
SRC_PATH = srcs
VISU_PATH = srcs
LIB_PATH = libft
REQ = -lft -lmlx
MLX_PATH = minilibx_macos
FW = -framework OpenGL -framework AppKit
LIB_INC_PATH = $(LIB_PATH)/includes
LIB = $(LIB_PATH)/libft.a
MLX = $(MLX_PATH)/libmlx.a

SRC =	$(SRC_PATH)/main.c			\
		$(SRC_PATH)/read.c			\
		$(SRC_PATH)/strat.c			\
		$(SRC_PATH)/place_piece.c	\

VISU_SRV = $(VISU_PATH)/visu.c

OSRC = $(SRC:.c=.o)
VOSRC = $(VISU_SRC:.c=.o)

DEPS := $(SRC:.c=.d)
VDEPS = $(VISU_SRC:.c=.d)

NO_COLOR = \x1b[0m
OK_COLOR = \x1b[32;01m
DEL_COLOR = \x1b[33m

all: $(NAME)

$(NAME): $(LIB) $(MLX) $(OSRC)
#	$(VISU)
	@echo "Compiling..."
	@$(CC) $(CFLAGS) $(OSRC) $(FW) -o $@ $(LIB) $(MLX)
	@echo "$(OK_COLOR)$@ compiled.$(NO_COLOR)"

$(VISU): $(LIB) $(MLX) $(VOSRC)

$(LIB):
	@make -C $(LIB_PATH)

$(MLX):
	@make -C $(MLX_PATH)

%.o: %.c
	@$(CC) $(CFLAGS) $(DFLAGS) -I $(LIB_INC_PATH) -I $(INC_PATH) -I $(MLX_PATH) -c $< -o $@

clean:
	@make -C libft clean
	@/bin/rm -f $(OSRC)
	@/bin/rm -f $(VOSRC)
	@/bin/rm -f $(DEPS)
	@echo "$(DEL_COLOR)Cleaning temporary files.$(NO_COLOR)"

fclean: clean
	@make -C libft fclean
	@/bin/rm -f $(NAME)
	@/bin/rm -f $(VISU)
	@/bin/rm -f a.out
	@echo "$(DEL_COLOR)Delete $(NAME) file.$(NO_COLOR)"

re: fclean all

.PHONY: all clean fclean re

-include $(DEPS)
