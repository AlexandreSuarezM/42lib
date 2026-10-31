NAME: swap.a

FLAGS: -Wall -Werror -Wextra

SCR: 

OBS: $(SCR:.o=.c)

all: $(NAME)

$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)

%.c: %.o swap.h
	cc $(FLAGS) -c $< -o $@


main: $(name)
	cc main.c swap.a -o main 

clean:
	rm -f $(OBJ)

flclean: clean
	rm -f $(NAME) 

re: flclean
	$(NAME) all