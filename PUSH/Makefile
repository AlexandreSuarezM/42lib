
NAME = push_swap

CC = cc
CFLAGS = -Wall -Wextra -Werror

SRC = main.c \
      disorder.c \
      ft_lstclear.c \
      ft_lstnew.c \
      ft_lstadd_to.c \
      ft_lstdelone.c

OBJ = $(SRC:.c=.o)

HEADER = pushswap.h

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

main1: $(NAME)
	./$(NAME) --complexity

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
