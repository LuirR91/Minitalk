# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: luiribei <luiribei@student.42lisboa.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/08 10:59:19 by luiribei          #+#    #+#              #
#    Updated: 2024/11/11 21:41:15 by luiribei         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Standard
CLIENT		= client
SERVER		= server

# Directories
LIBFT		= ./libft/libft.a
INC			= inc/
SRC			= src/
OBJ			= obj/

# Compiler and CFLAGS
CC			= @cc
CFLAGS		= -Wall -Wextra -Werror
RM			= rm -f


# Source Files
CLIENT_SRC	= $(SRC)client.c
SERVER_SRC	= $(SRC)server.c

# Object Files
CLIENT_OBJ	= $(OBJ)client.o
SERVER_OBJ	= $(OBJ)server.o

# Rules
all:		$(CLIENT) $(SERVER)

$(LIBFT):
			@make -s -C ./libft

$(SERVER):	$(SERVER_OBJ) $(LIBFT)
			@echo "Make .o and server"
			$(CC) $(CFLAGS) $(SERVER_OBJ) $(LIBFT) -o $(SERVER)
			@echo "$(SERVER) has been successfully built"

$(CLIENT):	$(CLIENT_OBJ) $(LIBFT)
			@echo "Make .o and client"
			$(CC) $(CFLAGS) $(CLIENT_OBJ) $(LIBFT) -o $(CLIENT)
			@echo "$(CLIENT) has been successfully built"

$(SERVER_OBJ): $(SERVER_SRC)
			@mkdir -p $(OBJ)
			@echo "Compiling $(SERVER_SRC)..."
			$(CC) $(CFLAGS) -I$(INC) -c $(SERVER_SRC) -o $(SERVER_OBJ)

$(CLIENT_OBJ): $(CLIENT_SRC)
			@mkdir -p $(OBJ)
			@echo "Compiling $(CLIENT_SRC)..."
			$(CC) $(CFLAGS) -I$(INC) -c $(CLIENT_SRC) -o $(CLIENT_OBJ)

clean:
			$(RM) -r $(OBJ)
			@make -s clean -C ./libft
			@echo "Cleaned up .o files."

fclean:		clean
				@$(RM) $(CLIENT) $(SERVER)
				@make -s fclean -C ./libft
				@echo "Removed executables."

re:			fclean all
				@echo "Fully rebuilt"

.PHONY:	all clean fclean re