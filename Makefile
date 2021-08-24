NAME = philo
CC = clang

CCFLAGS = -Wall -Wextra -Werror

INCLUDES = ./includes

HEADER = $(INCLUDES)/philo.h $(INCLUDES)/struct.h
 
HEADERS = minitalk.h struct.h

SRCS =	srcs/main.c \
		srcs/tools.c \
		srcs/init.c

OBJS = $(SRCS:.c=.o)

$(NAME): 

$(OBJS): %.o: %.c $(HEADER)
	$(CC) $(CFLAGS) -c $<  -I $(INCLUDES) -o $@

all: $(NAME)


philo: $(OBJS) $(HEADER) 
	$(CC) $(OBJS) -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re:
	$(MAKE) fclean
	$(MAKE) all

norm:
	norminette $(SRCS) | grep "Error"
	norminette $(INCLUDES) | grep "Error"