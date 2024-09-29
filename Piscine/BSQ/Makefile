NAME = bsq

SRC_DIR = src
INC_DIR = headers

SRC_FILES = main.c actions.c checks.c input.c utilities.c

SRC = $(addprefix $(SRC_DIR)/, $(SRC_FILES))
OBJ = $(SRC:.c=.o)

CC = cc
CFLAGS = -g -Wall -Wextra -Werror -I$(INC_DIR)

all: $(NAME)

$(NAME): $(OBJ)
	@echo "Compilando objetos en $(NAME)"
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJ)

$(SRC_DIR)/%.o: $(SRC_DIR)/%.c
	@echo "Compilando objetos : $<"
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@echo "Eliminando arhivos basura ..."
	@rm -f $(OBJ)

fclean: clean
	@echo "Eliminando $(NAME)"
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
