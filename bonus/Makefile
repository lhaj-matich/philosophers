NAME = philo_bonus
CC = gcc
CFLAGS = -Wall 
HEADER = philosophers.h

SRC = main_bonus.c init_bonus.c parse_bonus.c philo_bonus.c utils_bonus.c checker_bonus.c strcmp.c
OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ) $(HEADER)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

%.o : %.c
	$(CC) $(CFLAGS) -o $@ -c $<

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all