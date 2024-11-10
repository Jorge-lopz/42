# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jorlopez <jorlopez@student.42madrid.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/08 14:00:58 by jorlopez          #+#    #+#              #
#    Updated: 2024/11/08 14:00:58 by jorlopez         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
LIBFT = ./libft/libft.a
SRCS = ft_printf.c
OBJS = $(SRCS:.c=.o)
CC = cc
CFLAGS = #-Wall -Wextra -Werror
TEST = main
TEST_SRC = main.c

all: $(NAME) $(TEST)

$(LIBFT):
	$(MAKE) -C ./libft

$(NAME): $(OBJS) $(LIBFT)
	ar rcs $(NAME) $(OBJS) $(LIBFT)

$(TEST): $(NAME) $(TEST_SRC)
	$(CC) $(CFLAGS) $(TEST_SRC) -L. libftprintf.a -C ./libft/libft.a -o $(TEST)

clean:
	$(MAKE) clean -C ./libft
	rm -f $(OBJS)

fclean: clean
	$(MAKE) fclean -C ./libft
	rm -f $(NAME) $(TEST)

re: fclean all

run: $(TEST)
	./$(TEST)