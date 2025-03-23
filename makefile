CC = gcc
CFLAGS = -Wall -Wextra -Werror
OBJ_DIR = obj
SRC_DIR = src
OBJS = $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(wildcard $(SRC_DIR)/*.c))
LIB = fillit.a
PROGRAM_NAME = fillit
##----------------------------------


$(PROGRAM_NAME): $(LIB)
	$(CC) -o $(PROGRAM_NAME) $(LIB) ../LIBFT/libft.a -I ../LIBFT/includes/


$(LIB): main.o $(OBJ_DIR) $(OBJS)
	ar rcs $(LIB) $(OBJ_DIR)/*.o
$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)
main.o: $(OBJ_DIR)
	$(CC) $(CFLAGS) -c main.c -o $(OBJ_DIR)/main.o -I ../LIBFT/includes -I includes/ 

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@ -I includes/ -I ../LIBFT/includes/

clean:
	rm $(OBJ_DIR)/*.o
fclean: clean
	rm -rf $(OBJ_DIR) $(LIB)

all: $(PROGRAM_NAME)
re: fclean all
