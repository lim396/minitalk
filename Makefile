CC = gcc
CFLAGS = -Wall -Wextra -Werror

NAME = minitalk
CLIENT = client
SERVER = server
HEADER = minitalk.h
LIBFT= ./libft/libft.a

C_SRC = client.c
S_SRC = server.c

ifdef WITH_BONUS
C_SRC = client_bonus.c
S_SRC = server_bonus.c
HEADER = minitalk_bonus.h
endif

C_OBJ = $(C_SRC:.c=.o)
S_OBJ = $(S_SRC:.c=.o)


all: $(NAME)

$(NAME): $(CLIENT) $(SERVER)

$(LIBFT):
	$(MAKE) -C ./libft

$(CLIENT): $(C_OBJ) $(HEADER) $(LIBFT)
	$(CC) $(CFLAGS) -o $@ $(C_OBJ) $(LIBFT)

$(SERVER): $(S_OBJ) $(HEADER) $(LIBFT)
	$(CC) $(CFLAGS) -o $@ $(S_OBJ) $(LIBFT)

bonus:
	$(MAKE) WITH_BONUS=1

clean:
	$(MAKE) clean -C ./libft
	$(RM) *.o

fclean: clean
	$(RM) $(CLIENT) $(SERVER)

re: fclean all

.PHONY: all clean fclean re bonus
