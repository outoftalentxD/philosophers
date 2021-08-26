NAME = philo
CC = gcc

CFLAGS = -Wall -Wextra -Werror

PTHREADFLAG = -pthread

INCLUDES = ./includes

HEADER = $(INCLUDES)/philo.h $(INCLUDES)/struct.h
 
HEADERS = minitalk.h struct.h

SRCS =	srcs/main.c \
		srcs/tools.c \
		srcs/init.c \
		srcs/forks.c \
		srcs/actions.c \
		srcs/monitor.c \
		srcs/ft_calloc.c \
		srcs/ft_atoi.c		

OBJS = $(SRCS:.c=.o)

$(NAME): 

$(OBJS): %.o: %.c $(HEADER)
	$(CC) $(CFLAGS) -c $<  -I $(INCLUDES) -o  $@

all: $(NAME)


philo: $(OBJS) $(HEADER) 
	$(CC) $(OBJS) $(PTHREADFLAG) -o $@

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