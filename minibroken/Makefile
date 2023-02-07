# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: mbernede <mbernede@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2023/02/02 22:47:37 by mbernede      #+#    #+#                  #
#    Updated: 2023/02/07 17:41:25 by mbernede      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

SERVER	:= server

CLIENT	:= client

SRV 	=	server.c

CLT	=	client.c

UTL		=	utils.c\
			ft_itoa.c\
			com.c

CC = cc

#FLAGS = -Wall -Wextra -Werror

all : $(SERVER) $(CLIENT)

${SERVER}:
	@$(CC) $(FLAGS) -o $(SERVER) $(SRV) $(UTL)

${CLIENT}:
	@$(CC) $(FLAGS) -o $(CLIENT) $(CLT) $(UTL)


clean: 
	@${RM} ${CLIENT} $(SERVER)

fclean: 	clean

re :	fclean all

.PHONY: re fclean all clean
