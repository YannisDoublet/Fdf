# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yadouble <yadouble@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/09/28 18:32:07 by yadouble          #+#    #+#              #
#    Updated: 2018/09/28 18:32:14 by yadouble         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol
CC = gcc
CFLAGS = -Wall -Wextra -Werror -Ofast -flto -march=native
FRAMEWORK = -framework OpenGL -framework AppKit
SRCS_DIR = srcs
OBJ_DIR = obj
SRCS = main.c
SRCS := $(addprefix $(SRCS_DIR)/,$(SRCS))
OBJ = $(subst $(SRCS_DIR),$(OBJ_DIR),$(SRCS:.c=.o))

all : $(NAME)

$(NAME) : $(OBJ)
	@make -C libft
	@make -C minilibx_macos
	@$(CC) -o $(NAME) $(CFLAGS) $(OBJ) $(FRAMEWORK) \
	libft/libft.a minilibx_macos/libmlx.a

$(OBJ_DIR)/%.o : $(SRCS_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	@$(CC) -o $@ -Iincludes -c $(CFLAGS) $<

clean :
	@make -C libft clean
	@make -C minilibx_macos clean
	@rm -rf $(OBJ_DIR)

fclean : clean
	@make -C libft fclean
	@make -C minilibx_macos fclean
	@rm -f $(NAME)

re : fclean all
