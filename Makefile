CC= cc
CFLAGS= -Wall -Wextra -Werror
NAME= server
NAME1= client
OBJ= server.c
OBJ1= client.c ft_atoi.c
OBJ_O= $(OBJ:.c=.o)
OBJ1_O= $(OBJ1:.c=.o)

all: $(NAME)

$(NAME): $(OBJ_O) $(OBJ1_O)
	$(CC) $(CFLAGS) $(OBJ_O) -o $(NAME)
	$(CC) $(CFLAGS) $(OBJ1_O) -o $(NAME1)

clean:
	rm -rf $(OBJ_O) $(OBJ1_O)


fclean: clean
	rm -rf $(NAME1) $(NAME)