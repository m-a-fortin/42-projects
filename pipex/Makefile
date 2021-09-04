# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mafortin <mafortin@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/08/30 14:29:31 by mafortin          #+#    #+#              #
#    Updated: 2021/08/30 14:39:50 by mafortin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= pipex

LIBFT		= ft
LIBFTDIR	= libft
MAKELIBFT	= @$(MAKE) -C $(LIBFTDIR)

SRC			= src
INC			= include
OBJ			= obj
CFILES		= main.c px_parsing.c px_error.c
HFILES		= pipex.h
OFILES		= $(CFILES:.c=.o)
SRCS		= $(addprefix $(SRC)/, $(CFILES))
OBJS		= $(addprefix $(OBJ)/, $(OFILES))
HEADERS		= $(addprefix $(INC)/, $(HFILES))

CC			= clang
CFLAGS		= -Wall -Wextra -Werror
RM			= rm -rf

$(OBJ)/%.o:	$(SRC)/%.c
			@$(CC) $(CFLAGS) -I$(LIBFTDIR) -I$(INC) -c $< -o $@

$(NAME):	$(OBJ) $(OBJS)
			$(MAKELIBFT)
			@$(CC) $(OBJS) -L$(LIBFTDIR) -l$(LIBFT) -o $(NAME)
			@echo "\\n\033[32;5m PIPEX IS READY \033[0m"

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