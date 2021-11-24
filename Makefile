# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fboumell <fboumell@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/24 11:58:52 by fboumell          #+#    #+#              #
#    Updated: 2021/11/24 13:43:29 by fboumell         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME_C	= client

NAME_S = server
	
CC	= gcc

CFLAGS	= -Wall -Wextra -Werror

RM	= rm -f

SRCS	= server.c client.c utils.c

OBJS		=	${SRCS:.c=.o}

$(NAME_C):	${OBJS}

$(NAME_S):	${OBJS}
				
%.o :		%.c 
			${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

all : 		${NAME_C} ${NAME_S}

clean : 
			${RM} ${OBJS}

fclean : 	clean
			${RM} ${NAME_C} ${NAME_S}

re : 		fclean all

.PHONY : 	all clean fclean re