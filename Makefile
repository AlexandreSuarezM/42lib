NAME = push_swap.a\


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
	  showlist.c \
      sorts/selectionsort.c \
	  ft_strlen.c \
	  ft_lstsize.c

OBJ = $(SRC:.c=.o)


HEADER = pushswap.h

all: $(NAME)

$(NAME): $(OBJ) $(HEADER)  $(NAME2)
	ar rcs $(NAME) $(OBJ)

%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

main: $(NAME) main.c $(HEADER)
	cc main.c  $(NAME) -o pushexe

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
