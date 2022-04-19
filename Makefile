# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cben-bar <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/07 23:40:46 by cben-bar          #+#    #+#              #
#    Updated: 2022/04/19 17:01:36 by cben-bar         ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

NAME	=	pipex

SRCS 	=	srcs/pipex.c srcs/utils.c srcs/ft_split.c srcs/ft_strjoin.c srcs/ft_strlen.c srcs/ft_strnstr.c srcs/ft_putchar_fd.c srcs/ft_putstr_fd.c srcs/line_count.c srcs/cleaner.c

OBJS 	=	${SRCS:.c=.o}

HEADER	=	-Iincludes

CC 		=	gcc

CFLAGS 	=	-Wall -Wextra -Werror

DEPS	=	./includes/pipex.h

%.o :		%.c ${DEPS} Makefile
				@${CC} ${CFLAGS} ${HEADER} -c $< -o $(<:.c=.o)

all: 		${NAME}

${NAME}:	${OBJS} ${DEPS} Makefile
				@$(CC) ${OBJS} -o ${NAME}

clean:
				@rm -f ${OBJS}

fclean: 	clean
				@rm -f ${NAME}

re:			fclean all

.PHONY:		all clean fclean re
