# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eprusako <eprusako@student.42madrid.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/22 16:23:47 by eprusako          #+#    #+#              #
#    Updated: 2023/06/14 13:52:05 by eprusako         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


#COLORS
GREEN       = \033[1;32m
CYAN        = \033[1;36m

#COMP
NAME = fractol
CC = gcc
CFLAGS = -v
#  -Wall -Werror -Wextra
DEBUG = -g
SRC_FILES = src/main.c \
		src/init.c \
		src/img_pix_put.c \
		src/keypress.c

OBJS = $(SRC_FILES:%.c=%.o)



##INCLUDES
LIBFT = ./inc/libft/
MLX = ./inc/mlx/


OS := $(shell uname)


INC := -Imlx
LFLAGS := -lmlx -lm -framework OpenGL -framework AppKit
LIBS := ./inc/libft/libft.a


all: $(NAME)


$(NAME): $(OBJS)
	@echo "$(GREEN)Created binary objects"
	@make -sC $(LIBFT)
	@echo  "$(GREEN)Creating libraries files"
	
	@ $(CC) $(CFLAGS) $(OBJS) -o $(NAME) $(LIBS) $(LFLAGS) 
	@echo "$(GREEN)Compiled succesfully"


clean:
	@echo "$(CYAN)Supressing binary objects"
	@rm -f $(OBJS)

fclean: clean 
	@echo "$(CYAN)Supressing binary executable"
	@rm -f $(NAME)

re: all fclean

%.o: %.c
	@ $(CC) $(CFLAGS) $(INC) -c $< -o $@



.PHONY: all, clean, fclean, re