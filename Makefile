# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: luiribei <luiribei@student.42lisboa.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/08 10:59:19 by luiribei          #+#    #+#              #
#    Updated: 2024/11/14 15:28:34 by luiribei         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Standard
SERVER					= server
SERVER_BONUS			= server_bonus
CLIENT					= client
CLIENT_BONUS			= client_bonus

# Directories
LIBFT					= ./libft/libft.a
INC						= inc/
SRC						= src/
OBJ						= obj/

# Compiler and CFLAGS
CC						= @cc
CFLAGS					= -Wall -Wextra -Werror
RM						= @rm -f

# Source Files
SERVER_SRC				= $(SRC)server.c
SERVER_BONUS_SRC		= $(SRC)server_bonus.c
CLIENT_SRC				= $(SRC)client.c
CLIENT_BONUS_SRC		= $(SRC)client_bonus.c

# Object Files
SERVER_OBJ				= $(OBJ)server.o
SERVER_BONUS_OBJ		= $(OBJ)server_bonus.o
CLIENT_OBJ				= $(OBJ)client.o
CLIENT_BONUS_OBJ		= $(OBJ)client_bonus.o

# Rules
all:					$(CLIENT) $(SERVER)

bonus:					$(CLIENT_BONUS) $(SERVER_BONUS)

$(LIBFT):
						@make -s -C ./libft

$(SERVER):				$(SERVER_OBJ) $(LIBFT)
							@echo "Building $(SERVER)..."
							$(CC) $(CFLAGS) $(SERVER_OBJ) $(LIBFT) -o $(SERVER)
							@echo "$(SERVER) has been successfully built"

$(SERVER_BONUS):		$(SERVER_BONUS_OBJ) $(LIBFT)
							@echo "Building $(SERVER_BONUS)..."
							$(CC) $(CFLAGS) $(SERVER_BONUS_OBJ) $(LIBFT) -o $(SERVER_BONUS)
							@echo "$(SERVER_BONUS) has been successfully built"

$(CLIENT):				$(CLIENT_OBJ) $(LIBFT)
							@echo "Building $(CLIENT)..."
							$(CC) $(CFLAGS) $(CLIENT_OBJ) $(LIBFT) -o $(CLIENT)
							@echo "$(CLIENT) has been successfully built"

$(CLIENT_BONUS):		$(CLIENT_BONUS_OBJ) $(LIBFT)
							@echo "Building $(CLIENT_BONUS)..."
							$(CC) $(CFLAGS) $(CLIENT_BONUS_OBJ) $(LIBFT) -o $(CLIENT_BONUS)
							@echo "$(CLIENT_BONUS) has been successfully built"

$(SERVER_OBJ):			$(SERVER_SRC)
							@mkdir -p $(OBJ)
							@echo "Compiling $(SERVER_SRC)..."
							$(CC) $(CFLAGS) -I$(INC) -c $(SERVER_SRC) -o $(SERVER_OBJ)

$(SERVER_BONUS_OBJ):	$(SERVER_BONUS_SRC)
							@mkdir -p $(OBJ)
							@echo "Compiling $(SERVER_BONUS_SRC)..."
							$(CC) $(CFLAGS) -I$(INC) -c $(SERVER_BONUS_SRC) -o $(SERVER_BONUS_OBJ)

$(CLIENT_OBJ):			$(CLIENT_SRC)
							@mkdir -p $(OBJ)
							@echo "Compiling $(CLIENT_SRC)..."
							$(CC) $(CFLAGS) -I$(INC) -c $(CLIENT_SRC) -o $(CLIENT_OBJ)

$(CLIENT_BONUS_OBJ):	$(CLIENT_BONUS_SRC)
							@mkdir -p $(OBJ)
							@echo "Compiling $(CLIENT_BONUS_SRC)..."
							$(CC) $(CFLAGS) -I$(INC) -c $(CLIENT_BONUS_SRC) -o $(CLIENT_BONUS_OBJ)

clean:
						$(RM) -r $(OBJ)
							@make -s clean -C ./libft
							@echo "Cleaned up .o files."

fclean:					clean
							@$(RM) $(CLIENT) $(CLIENT_BONUS) $(SERVER) $(SERVER_BONUS)
							@make -s fclean -C ./libft
							@echo "Removed executables."

re:						fclean all
							@echo "Fully rebuilt"

.PHONY:	all bonus clean fclean re
