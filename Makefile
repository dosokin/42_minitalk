SERVER_NAME = server
SERVER_SRCS = src/main_server.c src/server_error.c src/lst_utils.c src/server_receiver.c
SERVER_OBJS = $(SERVER_SRCS:.c=.o)

CLIENT_NAME = client
CLIENT_SRCS = src/main_client.c src/client_sender.c
CLIENT_OBJS = $(CLIENT_SRCS:.c=.o)

CC = cc
FLAGS = -g -Wall -Werror -Wextra -I includes/
LIBS = src/libft/
BUILT_LIBS = src/libft/libft.a

all : $(SERVER_NAME) $(CLIENT_NAME)

$(SERVER_NAME) : $(BUILT_LIBS) $(SERVER_OBJS)
	$(CC) $(FLAGS) $(SERVER_OBJS) $(BUILT_LIBS) -o $(SERVER_NAME)

$(CLIENT_NAME) : $(BUILT_LIBS) $(CLIENT_OBJS)
	$(CC) $(FLAGS) $(CLIENT_OBJS) $(BUILT_LIBS) -o $(CLIENT_NAME)

%.o : %.c
	$(CC) $(FLAGS) -c $< -o $@

clean :
	for dir in $(LIBS); do \
  		make clean -C $$dir; \
  	done
	rm -rf $(SERVER_OBJS)
	rm -rf $(CLIENT_OBJS)

fclean : clean
	for dir in $(LIBS); do \
      	make fclean -C $$dir; \
    done
	rm -rf $(SERVER_NAME)
	rm -rf $(CLIENT_NAME)

re : fclean all

$(BUILT_LIBS) : $(LIBS)
	for dir in $(LIBS); do \
  		make -C $$dir; \
  	done

