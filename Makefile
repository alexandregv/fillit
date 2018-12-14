# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: achoquel <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/12/06 12:01:01 by achoquel          #+#    #+#              #
#    Updated: 2018/12/14 16:08:50 by aguiot--         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= fillit

SRCS	=	main.c		\
			errors.c	\
			map.c		\
			tetri.c		\
			backtrack.c

OBJS	= 	$(SRCS:.c=.o)

CC		=	gcc

CFLAGS	+=	-Wall -Wextra -Werror -g

LIB		=	-L./libft/ -lft

RM		=	/bin/rm -f

all		:	$(NAME)

$(NAME)	:	$(OBJS)
			make  -C libft/
			$(CC) -o $(NAME) $(OBJS) $(LIB)

clean	:
			make -C libft/ clean
			$(RM) $(OBJS)

fclean	:	clean
			$(RM) $(NAME)
			$(RM) libft/libft.a

re		:	fclean all
