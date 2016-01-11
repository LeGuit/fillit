# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gwoodwar <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/12/03 16:00:57 by gwoodwar          #+#    #+#              #
#    Updated: 2016/01/11 16:30:16 by gwoodwar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC =		gcc
FLAGS =		-Wall -Werror -Wextra
NAME =		fillit
LIB =		libft/libftprintf.a
HEAD =		fillit.h

SRCS =		fillit.c \
			is_valid.c \
			is_valid2.c \
			processing.c \
			print_piece.c \
			solve.c \
			opp_map.c \
			print_map.c \
			algo.c \
			main.c 

OBJS =		$(SRCS:.c=.o)

all:		$(NAME)

$(LIB):
	make -C libft/ fclean
	make -C libft/

$(NAME):	$(LIB) $(OBJS)
	$(CC) $(FLAGS) -o $@ $(OBJS) $(LIB)

%.o:		%.c
	$(CC) $(FLAGS) -I $(HEAD) -o $@ -c $<

clean:
	/bin/rm -f $(OBJS)
	make -C libft/ fclean

fclean: 	clean
	/bin/rm -f $(NAME)

re: 		fclean all
