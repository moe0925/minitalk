# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: moeota <moeota@student.42tokyo.jp>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/07 22:58:35 by moeota            #+#    #+#              #
#    Updated: 2023/03/09 04:36:36 by moeota           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror

CLIENT =	client
SERVER =	server

CLIENT_SRC =	client.c  ft_atoi.c ft_putchar_fd.c
SERVER_SRC =	server.c  ft_atoi.c ft_putchar_fd.c
PRINTF =			./ft_printf/libftprintf.a
PRINTF_DIR =		./ft_printf

CLIENT_OBJS :=	$(CLIENT_SRC:%.c=%.o)
SERVER_OBJS :=	$(SERVER_SRC:%.c=%.o)


all: $(CLIENT) $(SERVER)

$(NAME): all

$(CLIENT): $(PRINTF)
	$(CC) $(CFLAGS) $(CLIENT_SRC) -o $(CLIENT) $(PRINTF)

$(SERVER): $(PRINTF)
	$(CC) $(CFLAGS) $(SERVER_SRC) -o $(SERVER) $(PRINTF)

$(PRINTF):
	$(MAKE) -C ./ft_printf
	cp $(PRINTF) ./

clean:
	rm -f $(CLIENT_OBJS) $(SERVER_OBJS)
	$(MAKE) -C ./ft_printf clean

fclean: clean
	rm -f $(CLIENT) $(SERVER) printflibft.a
	$(MAKE) -C ./ft_printf fclean

re: fclean all

.PHONY:	all clean fclean re

# CC = cc
# CFLAGS = -Wall -Wextra -Werror
# MANDATORY_SERVER_SRCS = ft_atoi.c  server.c ft_putnbr_fd.c ft_putchar_fd.c
# # BONUS_SERVER_SRCS = ft_atoi.c  server_bonus.c ft_putnbr.c ft_putchar.c
# MANDATORY_SERVER_OBJS = $(MANDATORY_SERVER_SRCS:.c=.o)
# # BONUS_SERVER_OBJS = $(BONUS_SERVER_SRCS:.c=.o)
# SERVER = server
# MANDATORY_CLIENT_SRCS = client.c ft_atoi.c ft_putnbr_fd.c ft_putchar_fd.c
# # BONUS_CLIENT_SRCS = client_bonus.c ft_atoi.c ft_putnbr.c ft_putchar.c
# MANDATORY_CLIENT_OBJS = $(MANDATORY_CLIENT_SRCS:.c=.o)
# # BONUS_CLIENT_OBJS = $(BONUS_CLIENT_SRCS:.c=.o)
# CLIENT = client
# NAME = minitalk

# # ifdef BONUS
# #     CLIENT_OBJS = $(BONUS_CLIENT_OBJS)
# #     SERVER_OBJS = $(BONUS_SERVER_OBJS)
# # else
# CLIENT_OBJS = $(MANDATORY_CLIENT_OBJS)
# SERVER_OBJS = $(MANDATORY_SERVER_OBJS)
# # endif

# all: $(NAME)

# $(NAME): $(SERVER) $(CLIENT)

# $(SERVER): $(SERVER_OBJS)
#     $(CC) $(CFLAGS) $(SERVER_OBJS) -o $(SERVER) 

# $(CLIENT): $(CLIENT_OBJS)
#     $(CC) $(CFLAGS) $(CLIENT_OBJS) -o $(CLIENT)

# clean:
#     $(RM) $(SERVER_OBJS) $(CLIENT_OBJS) 
	
# fclean: clean
#     $(RM) $(SERVER)
#     $(RM) $(CLIENT)

# re: fclean all

# # bonus:
# #     @make BONUS=1 all

# .PHONY: make clean fclean re bonus
# # CFLAGS = -Wall -Wextra -Werror

# CC = cc

# NAME = minitalk.a

# MANDATORY_CLIENT_SRCS = client.c ft_atoi.c ft_putchar_fd.c ft_putnbr_fd.c

# MANDATORY_SERVER_SRCS = server.c ft_atoi.c ft_putchar_fd.c ft_putnbr_fd.c

# # SRCS = client.c server.c ft_atoi.c ft_putchar_fd.c

# # OBJS    = $(SRCS:.c=.o)

# MANDATORY_CLIENT_OBJS   = $(MANDATORY_CLIENT_SRCS:.c=.o)

# MANDATORY_SERVER_OBJS   = $(MANDATORY_SERVER_SRCS:.c=.o)


# INCDIR  = -I src

# SERVER = server.c

# CLIENT = client.c

# all: 		$(NAME) 

# CLIENT_OBJS = $(MANDATORY_CLIENT_OBJS)
# SERVER_OBJS = $(MANDATORY_SERVER_OBJS)


# $(NAME): $(SERVER) $(CLIENT)
# 	 $(AR) cr $@ $^

# $(SERVER): $(SERVER_OBJS)
# 	$(CC) $(CFLAGS) $(SERVER_OBJS) -O $(SERVER)

# $(CLIENT): $(CLIENT_OBJS)
# 	$(CC) $(CFLAGS) $(CLIENT _SERVER) -O $(SERVER)

# clean:
# 	-$(RM) $(SERVER_OBJS) $(CLIENT_OBJS)  

# fclean: clean
# 	-$(RM) $(SERVER) 
# 	-$(RM) $(CLIENT)


# re: fclean all

# .PHONY: clean fclean re

