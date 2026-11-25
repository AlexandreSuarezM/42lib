NAME = get_next_line.a

BUFFER_SIZE ?= 42

SRC = get_next_line.c get_next_line_utils.c get_next_line_b.c get_next_line_utils_b.c

OBJ= $(SRC:%.c=%.o)

all: $(NAME)

$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)

%.o: %.c get_next_line.h 
	cc -Wall -Wextra -Werror -D BUFFER_SIZE=$(BUFFER_SIZE) -c $< -o $@

main: $(NAME) main.c
	cc -Wall -Wextra -Werror -D BUFFER_SIZE=$(BUFFER_SIZE) -g main.c ./get_next_line.a -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re:	fclean
	$(MAKE) all
