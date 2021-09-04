# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mafortin <mafortin@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/07/27 19:25:11 by mafortin          #+#    #+#              #
#    Updated: 2021/09/03 12:23:25 by mafortin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= push_swap

LIBFT		= ft
LIBFTDIR	= libft
MAKELIBFT	= @$(MAKE) -C $(LIBFTDIR)

SRC			= src
INC			= include
OBJ			= obj
CFILES		= main.c parse.c move.c algo_small.c algo_big.c algo_utils.c error.c utils.c utils_2.c median.c
HFILES		= push_swap.h
OFILES		= $(CFILES:.c=.o)
SRCS		= $(addprefix $(SRC)/, $(CFILES))
OBJS		= $(addprefix $(OBJ)/, $(OFILES))
HEADERS		= $(addprefix $(INC)/, $(HFILES))

CC			= clang
CFLAGS		= -Wall -Wextra -Werror
RM			= rm -rf

$(OBJ)/%.o:	$(SRC)/%.c
			@$(CC) $(CFLAGS) -I$ -I$(INC) -c $< -o $@

$(NAME):	$(OBJ) $(OBJS)
			$(MAKELIBFT)
			@$(CC) $(OBJS) -L$(LIBFTDIR) -l$(LIBFT) -o $(NAME)
			@echo "\\n\033[32;5m PUSH_SWAP IS READY \033[0m"

$(OBJ):
			mkdir -p $(OBJ)

all:		$(NAME)

clean:
			$(MAKELIBFT) fclean
			$(RM) $(OBJS)

fclean:		clean
			$(RM) $(NAME)
			echo "\\n\033[31;5m CLEAN DONE \033[0m"

re:			fclean all

norme:
			$(MAKELIBFT) norme
			norminette $(SRCS) $(HEADERS)

.PHONY:		all clean fclean re norme
