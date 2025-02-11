server = server
client = client

server_bonus = server_bonus
client_bonus = client_bonus

CC = cc
FLAGS = -Wall -Wextra -Werror

all: $(server) $(client)

$(server): server.c
	$(CC) $(FLAGS) server.c -o $(server)

$(client): client.c
	$(CC) $(FLAGS) client.c -o $(client)

bonus: $(server_bonus) $(client_bonus)

$(server_bonus): server_bonus.c
	$(CC) $(FLAGS) server_bonus.c -o $(server_bonus)

$(client_bonus): client_bonus.c
	$(CC) $(FLAGS) client_bonus.c -o $(client_bonus)

clean:
	rm -f $(server) $(client)
	rm -f $(server_bonus) $(client_bonus)

re: clean all

.PHONY: all bonus clean fclean re