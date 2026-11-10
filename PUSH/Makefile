NAME = push_swap

CC = cc
CFLAGS = -Wall -Wextra -Werror -I.

SRC = main.c \
      disorder.c \
      compare.c \
      ft_lstadd_top.c \
      ft_lstclear.c \
      ft_lstdelone.c \
      ft_lstnew.c \
      ft_strcmp.c \
      Operations/push.c \
      Operations/rotate.c \
      Operations/rotateup.c \
      Operations/sabs.c \
      sorts/RadixSort.c \
      sorts/selectionsort.c

OBJ = $(SRC:.c=.o)

HEADER = pushswap.h

all: $(NAME)

$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)

%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

main1: $(NAME) main.c 
	./$(NAME) --simple 
main2: $(NAME) main.c 
	./$(NAME) --medium 
main3: $(NAME) main.c 
	./$(NAME) --complex
main4: $(NAME) main.c 
	./$(NAME) --adaptive

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
