# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fboumell <fboumell@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/24 11:58:52 by fboumell          #+#    #+#              #
#    Updated: 2021/11/26 14:40:21 by fboumell         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME_C	= client

NAME_S = server
	
CC	= gcc

CFLAGS	= -Wall -Wextra -Werror

RM	= rm -f

SRCS	= server.c client.c utils.c

OBJS		=	${SRCS:.c=.o}

all : 		${NAME_C} ${NAME_S}

server :	server.c utils.c 
			${CC} ${CFLAGS} server.c utils.c -o ${NAME_S}
			
client :	client.c utils.c 
			${CC} ${CFLAGS} client.c utils.c -o ${NAME_C}

clean : 
			${RM} ${OBJS}

fclean : 	clean
			${RM} ${NAME_C} ${NAME_S}

re : 		fclean all

.PHONY : 	all clean fclean re