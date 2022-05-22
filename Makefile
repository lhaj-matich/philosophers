NAME = philo
CC = gcc
CFLAGS = -Wall -Wextra -Werror
HEADER = philosophers.h

SRC = main.c init_philo.c parse.c philo.c utils.c checker.c
OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ) $(HEADER)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

%.o : %.c
	$(CC) $(CFLAGS) -o $@ -c $<

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(OBJ) $(NAME)

re: fclean all