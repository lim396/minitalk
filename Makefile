CC = gcc
CFLAGS = -Wall -Wextra -Werror

NAME = minitalk
CLIENT = client
SERVER = server
LIBFT= ./libft/libft.a

C_SRC= client.c
C_OBJ=$(C_SRC:.c=.o)
S_SRC= server.c
S_OBJ=$(S_SRC:.c=.o)

all: $(NAME)

$(NAME): $(CLIENT) $(SERVER)

$(LIBFT):
	$(MAKE) -C ./libft

$(CLIENT): $(C_OBJ) $(LIBFT)
	$(CC) $(CFLAGS) -o $@ $(C_OBJ) $(LIBFT)

$(SERVER): $(S_OBJ) $(LIBFT)
	$(CC) $(CFLAGS) -o $@ $(S_OBJ) $(LIBFT)

clean:
	$(MAKE) clean -C ./libft
	$(RM) $(C_OBJ) $(S_OBJ)

fclean: clean
	$(MAKE) fclean -C ./libft
	$(RM) $(CLIENT) $(SERVER)

re: fclean all

.PHONY: all clean fclean re
