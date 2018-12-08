# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: achoquel <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/12/06 12:01:01 by achoquel          #+#    #+#              #
#    Updated: 2018/12/07 13:19:32 by aguiot--         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= fillit

SRCS	=	main.c		\
			errors.c	\
			map.c		\
			lists.c		\
			tetri.c		\
			topleft.c		\

OBJS	= 	$(SRCS:.c=.o)

CC		=	gcc

CFLAGS	+=	-Wall -Wextra -Werror
CFLAGS = 
LIB		=	-L./libft/ -lft

RM		=	/bin/rm -f

all		:
			@make $(NAME)

$(NAME)	:	$(OBJS)
			$(CC) -o $(NAME) $(OBJS) $(LIB)

clean	:
			$(RM) $(OBJS)

fclean	:	clean
			$(RM) $(NAME)

re		:	fclean all
