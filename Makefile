# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gwoodwar <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/12/03 16:00:57 by gwoodwar          #+#    #+#              #
#    Updated: 2015/12/04 11:51:57 by gwoodwar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC =		gcc
FLAGS =		-Wall -Werror -Wextra
NAME =		fillit
LIB_NAME =	libft/libft.a
LIB =		-I libft/includes
LFT =		-L libft/ -lft

SRCS =		fillit.c \
			test_buf.c \
			processing.c \
			main.c \

OBJS =		$(SRCS:.c=.o)

all:		$(NAME)

libft/libft.a:
	make -C libft/ fclean
	make -C libft/

$(NAME):	$(LIB_NAME) $(OBJS)
	$(CC) $(FLAGS) -o $@ $(OBJS) $(LFT)

%.o:		%.c
	$(CC) $(FLAGS) $(LIB) -o $@ -c $<

clean:
	/bin/rm -f $(OBJS)

fclean: 	clean
	/bin/rm -f $(NAME)

re: 		fclean all
