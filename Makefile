# -*- MakeFile -*_

SERVER_TARGET = server 
CLIENT_TRGET = client 
SERVER_SRCS = server.c
CLIENT_SRCS = client.c

OBJ_DIR = obj
SERVER_OBJS = $(addprefix $(OBJ_DIR)/, $(SERVER_SRCS:.c=.o))
CLIENT_OBJS = $(addprefix $(OBJ_DIR)/, $(CLIENT_SRCS:.c=.o))

CC = cc 
CFLAGS = -Wall -Wextra -Werror -Llibft -lft -Ilibft/header -g

libftdir = libft
libftname = libft.a
LIBFT = $(libftdir)/$(libftname)

all: libft $(SERVER_TARGET) $(CLIENT_TRGET)

libft: $(LIBFT)

$(LIBFT)
	@$(MAKE) -C $(libftdir) bonus

$(SERVER_TARGET): libft/libft.a $(SERVER_OBJS) | libft
	$(CC) $(CFLAGS) $(SERVER_OBJS) $(LIBFT) -o $(SERVER_TARGET)

$(CLIENT_TRGET): libft/libft.a $(CLIENT_OBJS) | libft
	$(CC) $(CFLAGS) $(CLIENT_OBJS) $(LIBFT) -o $(CLIENT_TRGET)

$(OBJ_DIR)/%.o: %.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

clean:
	rm -f $(SERVER_OBJS) $(CLIENT_OBJS)
	rm -rf $(OBJ_DIR)
	$(MAKE) -C $(libftdir) clean

fclean: clean
	rm -f $(SERVER_TARGET) $(CLIENT_TRGET)
	$(MAKE) -C $(libftdir) fclean

re: fclean all

.PHONY: all clean fclean re libft