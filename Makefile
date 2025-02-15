server = server
client = client

server_bonus = server_bonus
client_bonus = client_bonus

src_server = server.c
src_client = client.c

src_server_bonus = server_bonus.c
src_client_bonus = client_bonus.c

obj_server = $(src_server:.c=.o)
obj_client = $(src_client:.c=.o)

obj_server_bonus = $(src_server_bonus:.c=.o)
obj_client_bonus = $(src_client_bonus:.c=.o)

printf = ft_printf/libftprintf.a

CC = cc
CFLAGS = -Wall -Wextra -Werror

all: $(server) $(client)

$(server): $(obj_server)
	make -C ft_printf
	$(CC) $(CFLAGS) $(obj_server) $(printf) -o $(server)

$(client): $(obj_client)
	$(CC) $(CFLAGS) $(obj_client) -o $(client)

bonus: $(server_bonus) $(client_bonus)

$(server_bonus): $(obj_server_bonus)
	make -C ft_printf
	$(CC) $(CFLAGS) $(obj_server_bonus) $(printf) -o $(server_bonus)

$(client_bonus): $(obj_client_bonus)
	$(CC) $(CFLAGS) $(obj_client_bonus) -o $(client_bonus)

clean:
	rm -f $(obj_server) $(obj_client) $(obj_server_bonus) $(obj_client_bonus)
	make clean -C ft_printf

fclean: clean
	rm -f $(server) $(client) $(server_bonus) $(client_bonus)
	make fclean -C ft_printf

re: fclean all

.PHONY: all clean fclean re bonus

.SGANDR: $(obj_client) $(obj_server) $(obj_client_bonus) $(obj_server_bonus)