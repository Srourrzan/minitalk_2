# -*- MakeFile -*_

SERVER_TARGET = server 
CLIENT_TARGET = client 
SERVER_SRCS = server.c server_utils.c
CLIENT_SRCS = client.c

OBJ_DIR = obj
SERVER_OBJS = $(addprefix $(OBJ_DIR)/, $(SERVER_SRCS:.c=.o))
CLIENT_OBJS = $(addprefix $(OBJ_DIR)/, $(CLIENT_SRCS:.c=.o))

CC = cc 
CFLAGS = -Wall -Wextra -Werror -Llibft -lft -Ilibft/header -g

libftdir = libft
libftname = libft.a
LIBFT = $(libftdir)/$(libftname)

all: libft $(SERVER_TARGET) $(CLIENT_TARGET)

libft: $(LIBFT)

$(LIBFT):
	echo "Building libft"
	@$(MAKE) -C $(libftdir) bonus

$(SERVER_TARGET): libft/libft.a $(SERVER_OBJS) | libft
	$(CC) $(CFLAGS) $(SERVER_OBJS) $(LIBFT) -o $(SERVER_TARGET)

$(CLIENT_TARGET): libft/libft.a $(CLIENT_OBJS) | libft
	$(CC) $(CFLAGS) $(CLIENT_OBJS) $(LIBFT) -o $(CLIENT_TARGET)

$(OBJ_DIR)/%.o: %.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

clean:
	rm -f $(SERVER_OBJS) $(CLIENT_OBJS)
	rm -rf $(OBJ_DIR)
	$(MAKE) -C $(libftdir) clean

fclean: clean
	rm -f $(SERVER_TARGET) $(CLIENT_TARGET)
	$(MAKE) -C $(libftdir) fclean

re: fclean all

.PHONY: all clean fclean re libft