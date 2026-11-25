NAME = libftprintf.a

SRC = \
    ft_printf.c \
    ft_putstr.c \
    ft_hextoa.c \
    ft_hextoa_upper.c \
    ft_pointtoa.c \
    ft_conv.c \
    ft_putcharc.c \
    ft_putnbr_signed.c \
    ft_putnbr_unsigned.c \

OBJ = $(SRC:.c=.o)

all: $(NAME) 

$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)

src/%.o: /%.c ft_printf.h
	cc -Wall -Wextra -Werror -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean 
	$(MAKE) all
