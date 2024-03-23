CC= cc
CFLAGS= -Wall -Wextra -Werror
NAME= server
NAME1= client

BNAME= server_bonus
BNAME1= client_bonus

OBJ= server.c
OBJ1= client.c ft_atoi.c

BOBJ= bonus/server_bonus.c
BOBJ1= bonus/client_bonus.c ft_atoi.c

OBJ_O= $(OBJ:.c=.o)
OBJ1_O= $(OBJ1:.c=.o)

BOBJ_O= $(OBJ:.c=.o)
BOBJ1_O= $(OBJ1:.c=.o)

all: $(NAME) $(NAME1)

$(NAME): $(OBJ_O)
	$(CC) $(CFLAGS) $(OBJ_O) -o $(NAME)

$(NAME1): $(OBJ1_O)
	$(CC) $(CFLAGS) $(OBJ1_O) -o $(NAME1)

bonus: $(BNAME) $(BNAME1)

$(BNAME): $(BOBJ_O)
	$(CC) $(CFLAGS) $(BOBJ_O) -o $(BNAME)

$(BNAME1): $(BOBJ1_O)
	$(CC) $(CFLAGS) $(BOBJ1_O) -o $(BNAME1)

clean:
	rm -rf $(OBJ_O) $(OBJ1_O) $(BOBJ_O) $(BOBJ1_O)


fclean: clean
	rm -rf $(NAME1) $(NAME) $(BNAME1) $(BNAME)

re: fclean all

.PHONY: clean

.SECONDARY: $(OBJ_O) $(OBJ1_O) $(BOBJ_O) $(BOBJ1_O)
