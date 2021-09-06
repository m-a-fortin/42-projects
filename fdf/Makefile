# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mafortin <mafortin@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/06 11:28:23 by mafortin          #+#    #+#              #
#    Updated: 2021/09/06 11:46:04 by mafortin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME =		fdf
OBJS_PATH =	objs
SRCS_PATH =	srcs
LIBFT =		libft

SRCS =		main.c

CC =		gcc
CFLAGS =	-Wall -Werror -Wextra -c -g
INCLUDES =	-Imlx_mac -Iincludes
LIBS =		-Lmlx_mac -lmlx -Llibft -lft -framework OpenGL -framework AppKit
OBJS =		$(SRCS:.c=.o)

SRCS_FULL =	$(addprefix srcs/, $(SRCS))
OBJS_FULL =	$(addprefix objs/, $(OBJS))

all: $(OBJS_PATH) $(NAME)

$(OBJS_PATH):
	@mkdir -p $(OBJS_PATH)
	@echo Created: Object directory

$(NAME): $(OBJS_FULL)
	@make re --no-print-directory -C ./libft
	@$(CC) $(OBJS_FULL) $(LIBS) -o $(NAME)
	@echo "\\n\033[32;1m MAKE DONE: FDF IS READY \033[0m \\n"

$(OBJS_PATH)/%.o: $(SRCS_PATH)/%.c
	@echo "Created: $@\033[1A\033[M"
	@$(CC) $(CFLAGS) $(INCLUDES) $< -o $@

clean:
	@make clean --no-print-directory -C ./libft
	@rm -rf $(OBJS_FULL) $(OBJS_PATH) 
	@echo "\033[36;1m CLEAN DONE \033[0m"

fclean: clean
	@make fclean --no-print-directory -C ./libft
	@rm -f $(NAME)
	@echo "\033[36;1m FCLEAN DONE \033[0m"

re: fclean all

.PHONY: all clean fclean re