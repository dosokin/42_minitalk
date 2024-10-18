LIB = libft.a
SRCS = ft_safe_atoi.c \
		ft_split.c \
		ft_strcmp.c \
		ft_strjoin.c \
		ft_strlen.c \
		ft_strdup.c \
		ft_itoa.c
OBJS = $(SRCS:.c=.o)
CFLAGS = -Wall -Werror -Wextra -I ../../includes/
CC = cc

all : $(LIB) clean

$(LIB) : $(OBJS)
	$(AR) rcs $(LIB) $(OBJS)

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean :
	rm -rf $(OBJS)

fclean : clean
	rm -rf $(LIB)

re : fclean all
