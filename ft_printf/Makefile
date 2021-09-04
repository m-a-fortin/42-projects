# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mafortin <mafortin@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/07/21 12:24:15 by mafortin          #+#    #+#              #
#    Updated: 2021/07/21 18:11:07 by mafortin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	libftprintf.a
LIBFT		=	libft/libft.a
MAKELIBFT	=	$(MAKE) -C libft

SRC			=	srcs
INC			=	include
LIBFT_INC	=	libft
CFILES		=	ft_printf.c ft_print_c.c ft_print_d_i.c ft_print_s.c ft_print_u.c ft_print_x.c ft_print_p.c
SRCS		=	$(addprefix $(SRC)/, $(CFILES))
OBJS		=	$(SRCS:.c=.o)

CC			=	gcc
LIBC		=	ar rcs
CFLAGS		=	-Wall -Werror -Wextra

RM			=	rm -rf
CP			=	cp

%.o:		%.c
			$(CC) $(CFLAGS) -c $< -o $@ -I$(INC) -I$(LIBFT_INC)

$(NAME):	$(OBJS)
			$(MAKELIBFT)
			$(CP) $(LIBFT) $(NAME)
			$(LIBC) $(NAME) $(OBJS)

all:		$(NAME)

clean:
			$(MAKELIBFT) clean
			$(RM) $(OBJS)

fclean:		clean
			$(MAKELIBFT) fclean
			$(RM) $(NAME)

re:			fclean all

.PHONY:		all clean fclean re norme bonus