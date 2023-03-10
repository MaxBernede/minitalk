# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: mbernede <mbernede@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2023/02/02 22:47:37 by mbernede      #+#    #+#                  #
#    Updated: 2023/03/10 16:20:14 by mbernede      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

SERVER	:= server

CLIENT	:= client

SRV 	=	server.c

CLT	=	client.c

UTL		=	utils.c

CC = cc

FLAGS = -Wall -Wextra -Werror

all : $(SERVER) $(CLIENT)

${SERVER}: $(SRV) $(UTL)
	@$(CC) $(FLAGS) -o $(SERVER) $(SRV) $(UTL)

${CLIENT}: $(CLT) $(UTL)
	@$(CC) $(FLAGS) -o $(CLIENT) $(CLT) $(UTL)


clean: 
	@${RM} ${CLIENT} $(SERVER)

fclean: 	clean

re :	fclean all

.PHONY: re fclean all clean
