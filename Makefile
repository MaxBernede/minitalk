# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: mbernede <mbernede@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2023/02/02 22:47:37 by mbernede      #+#    #+#                  #
#    Updated: 2023/02/02 22:49:40 by mbernede      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME := 

SRCS =  client.c\
		main_client.c\
		server_main.c\
		server.c\

CC = cc

FLAGS = -Wall -Wextra -Werror

OBJ_DIR	:=		./objs/
SRC_DIR :=		./srcs/

OBJ 	:= 		$(addprefix ${OBJ_DIR},${SRCS:.c=.o})

BON		:=		$(addprefix ${OBJ_DIR},${BONUS:.c=.o})

${NAME}:	${OBJ}
	@$(CC) -o $@ $^ $(LIBA)

all : $(NAME)

${OBJ_DIR}%.o:	${SRC_DIR}%.c $(LIBH)
	@${CC} ${CFLAGS} -o $@ -c $<

clean: 
	@${RM} ${OBJ}

fclean: 	clean
	@${RM} ${NAME}

re :	fclean all

.PHONY: re fclean all clean
