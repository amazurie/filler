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

CFLAGS = -Wall -Wextra -Werror

DFLAGS = -MMD

INC_PATH = includes
SRC_PATH = srcs
VISU_PATH = visu
LIB_PATH = libft
REQ = -lft -lmlx
MLX_PATH = minilibx_macos
FW = -framework OpenGL -framework AppKit
LIB_INC_PATH = $(LIB_PATH)/includes
LIB = $(LIB_PATH)/libft.a
MLX = $(MLX_PATH)/libmlx.a

VISU_SRC =	$(VISU_PATH)/visu.c			\
			$(VISU_PATH)/read.c			\
			$(VISU_PATH)/render.c		\
			$(VISU_PATH)/render_back.c	\
			$(VISU_PATH)/render_score.c	\
			$(VISU_PATH)/parse.c		\
			$(VISU_PATH)/extra.c

OSRC = $(SRC:.c=.o)
VOSRC = $(VISU_SRC:.c=.o)

DEPS := $(SRC:.c=.d)
VDEPS = $(VISU_SRC:.c=.d)

NO_COLOR = \x1b[0m
OK_COLOR = \x1b[32;01m
DEL_COLOR = \x1b[33m

all: $(NAME) $(VISU)

$(NAME): $(LIB) $(MLX) $(OSRC)
	@echo "Compiling..."
	@$(CC) $(CFLAGS) $(OSRC) $(FW) -o $@ $(LIB)
	@echo "$(OK_COLOR)$@ compiled.$(NO_COLOR)"

$(VISU): $(MLX) $(VOSRC)
	@echo "Compiling visu..."
	@$(CC) $(CFLAGS) $(VOSRC) $(FW) -o $@ $(LIB) $(MLX)
	@echo "$(OK_COLOR)$@ compiled.$(NO_COLOR)"

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
-include $(VDEPS)
