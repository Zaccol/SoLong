# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lzaccome <lzaccome@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/01 05:31:56 by lzaccome          #+#    #+#              #
#    Updated: 2021/12/01 05:41:43 by lzaccome         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

CC = clang

CFLAGS =  -Wall -Wextra -Werror #-g3 -fsanitize=address

SRCS =	srcs/main.c \
		srcs/get_next_line.c \
		srcs/gnl_utils.c \
		srcs/utils.c \
		srcs/error.c 

_GREY=	$'\033[1;30m
_RED=	$'\033[1;31m
_GREEN=	$'\033[1;32m
_YELLOW=$'\033[1;33m
_BLUE=	$'\033[1;34m
_PURPLE=$'\033[1;35m
_CYAN=	$'\033[1;36m
_WHITE=	$'\033[1;37m

OBJ = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
		@echo "$(_YELLOW)[Compilation ongoing ...]"
		@echo "$(_GREEN)[Compilation finished]"
		$(CC) $(CFLAGS) $(OBJ) -o $(NAME)
		@echo "$(_CYAN)[Executable created]"
		@echo [Name : so_long]

%o: %.c
	$(CC) $(FLAGS) -o $@ -c $< -I includes
	
clean:
	@rm -f $(OBJ)
	@echo "$(_RED)[All .o removed]"

fclean: clean
	@rm -f $(NAME)
	@echo "$(_RED)[Executable removed]"

re: fclean all

.PHONY : all bonus clean fclean re