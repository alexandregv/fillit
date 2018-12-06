# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: achoquel <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/12/06 12:01:01 by achoquel          #+#    #+#              #
#    Updated: 2018/12/06 12:14:31 by achoquel         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= fillit

SRCS	=	main.c			\
			fichier.c		\
			fichier.c		\
			fichier.c

OBJS	= 	$(SRCS:.c=.o)

CC		=	cc

CFLAGS	+=	-Wall -Wextra -Werror

LIB		=	-L. -lft

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
