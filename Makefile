# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: agiraud <agiraud@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/28 01:39:07 by agiraud           #+#    #+#              #
#    Updated: 2021/09/28 13:48:48 by agiraud          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	server
NAME2		=	client

CC			=	gcc -Werror -Wextra -Wall

SRCS_SERVER	=	srcs/server/server.c
SRCS_CLIENT	=	srcs/client/client.c

OBJS_SERVER	=	$(SRCS_SERVER:.c=.o)
OBJS_CLIENT	=	$(SRCS_CLIENT:.c=.o)

all : $(NAME) $(NAME2)

$(NAME) :
		@$(CC) libft/*.c -I libft/libft.h $(SRCS_SERVER) -o server
		@rm -rf *.o
		@echo "\033[032mServer Created\033[0m"

$(NAME2) : 
		@$(CC) libft/*.c -I libft/libft.h $(SRCS_CLIENT) -o client
		@rm -rf *.o
		@echo "\033[032mClient Created\033[0m"

clean :
		@rm -rf srcs/client/*.o srcs/server/*.o libft/*.o
		@echo "\033[32mAll Object files Removed\033[0m"

fclean : clean
		@rm -rf $(NAME) $(NAME2)
		@echo "\033[32mServer et Client Removed\033[0m"

re : fclean all

.PHONY: clean fclean re
