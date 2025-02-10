server = server
client = client

CC = cc
FLAGS = -Wall -Wextra -Werror

all: $(server) $(client)

$(server): server.c
	$(CC) $(FLAGS) server.c -o $(server)

$(client): client.c
	$(CC) $(FLAGS) client.c -o $(client)

clean:
	rm -f $(server) $(client)

re: clean all

.PHONY: all clean fclean re