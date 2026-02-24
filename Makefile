NAME_SERVER = server
NAME_CLIENT = client

SRC_SERVER = src/server.c
SRC_CLIENT = src/client.c
SRC_UTILS = utils/send.c

OBJ_SERVER = $(SRC_SERVER:.c=.o)
OBJ_CLIENT = $(SRC_CLIENT:.c=.o)
OBJ_UTILS = $(SRC_UTILS:.c=.o)

LIBFT = lib/libft.a

CC = cc
CFLAGS = -Wall -Wextra -Werror

all: $(NAME_SERVER) $(NAME_CLIENT)

$(NAME_SERVER): $(OBJ_SERVER) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJ_SERVER) $(LIBFT) -o $(NAME_SERVER)

$(NAME_CLIENT): $(OBJ_CLIENT) $(OBJ_UTILS) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJ_CLIENT) $(OBJ_UTILS) $(LIBFT) -o $(NAME_CLIENT)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ_SERVER) $(OBJ_CLIENT) $(OBJ_UTILS)

fclean: clean
	rm -f $(NAME_SERVER) $(NAME_CLIENT)

re: fclean all

.PHONY: all clean fclean re
