# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cben-bar <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/06 15:13:54 by cben-bar          #+#    #+#              #
#    Updated: 2022/04/06 15:45:56 by cben-bar         ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

NAME			=	pipex

SRCS			=	srcs/pipex.c srcs/utils.c srcs/ft_split.c srcs/ft_strnstr.c srcs/ft_strlen.c srcs/ft_strjoin.c

OBJS 			=	${SRCS:.c=.o}

HEADER			=	-Iincludes

CC 				=	gcc

CFLAGS			=	-Wall -Wextra -Werror -g

DEPENDENCIES	=	./includes/pipex.h

.c.o			:	%.o : %.c ${DEPENDENCIES}
						${CC} ${CFLAGS} ${HEADER} -c $< -o $(<:.c=.o)

all				: 	${NAME}

${NAME}			:	${OBJS}
						$(CC) ${CFLAGS} ${OBJS} -o ${NAME}

clean			:
						rm -f ${OBJS}

fclean			: 	clean
						rm -f ${NAME}

re				:	fclean all

.PHONY			:	all clean fclean re
