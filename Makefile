SRC_FILES= main.c
OBJ_FILES= $(SRC_FILES:.c=.o)
CC=clang
CC_FLAGS= -Wall -Wextra -Werror -g
NAME=minvim
all:
	$(CC) $(CC_FLAGS) $(SRC_FILES) -o $(NAME)

clean:
	rm -f $(OBJ_FILES)
