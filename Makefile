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

NAME = amazurie.filler

CC = gcc

CFLAGS = -Wall -Wextra -Werror

DFLAGS = -MMD

INC_PATH = includes
SRC_PATH = srcs
LIB_PATH = libft
LIB_INC_PATH = $(LIB_PATH)/includes
LIB = $(LIB_PATH)/libft.a

SRC =	$(SRC_PATH)/main.c			\
		$(SRC_PATH)/read.c			\
		$(SRC_PATH)/strat.c			\
		$(SRC_PATH)/place_piece.c	\

OSRC = $(SRC:.c=.o)

DEPS := $(SRC:.c=.d)

NO_COLOR = \x1b[0m
OK_COLOR = \x1b[32;01m
DEL_COLOR = \x1b[33m

all: $(NAME)

$(NAME): $(LIB) $(OSRC)
	@echo "Compiling..."
	@$(CC) $(CFLAGS) $(OSRC) -o $@ $(LIB)
	@echo "$(OK_COLOR)$@ compiled.$(NO_COLOR)"
	@make -C visu

$(LIB):
	@make -C $(LIB_PATH)

%.o: %.c
	@$(CC) $(CFLAGS) $(DFLAGS) -I $(LIB_INC_PATH) -I $(INC_PATH) -c $< -o $@

clean:
	@make -C $(LIB_PATH) clean
	@make -C visu clean
	@/bin/rm -f $(OSRC)
	@/bin/rm -f $(DEPS)
	@echo "$(DEL_COLOR)Cleaning temporary files.$(NO_COLOR)"

fclean: clean
	@make -C $(LIB_PATH) fclean
	@make -C visu fclean
	@/bin/rm -f $(NAME)
	@echo "$(DEL_COLOR)Delete $(NAME) file.$(NO_COLOR)"

re: fclean all

.PHONY: all clean fclean re

-include $(DEPS)
