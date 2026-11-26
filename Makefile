NAME		= push_swap
CHECKER		= checker
LIB			= push_swap.a

CC			= cc
CFLAGS		= -Wall -Wextra -Werror
INCLUDES	= -I.

HEADER		= pushswap.h

# ---------------------------------------------------------------------------- #
#  Program sources (all at the root of the repository)                         #
# ---------------------------------------------------------------------------- #

MAIN_SRC	= push_swap.c
CHECKER_SRC	= checkers.c

UTILS_SRC	= ft_atoi.c \
			  ft_isdigit.c \
			  ft_lstadd_top.c \
			  ft_lstclear.c \
			  ft_lstdelone.c \
			  ft_lstnew.c \
			  ft_lstsize.c \
			  ft_split.c \
			  ft_strcmp.c \
			  ft_strlen.c \
			  ft_substr.c \
			  parse.c

OPS_SRC		= push.c \
			  rotate.c \
			  rotateup.c \
			  sabs.c \
			  op_log.c

SORTS_SRC	= disorder.c \
			  RadixSort.c \
			  selectionsort.c \
			  chunking.c \
			  adaptive.c \
			  bench.c

SRC			= $(UTILS_SRC) $(OPS_SRC) $(SORTS_SRC)

# ---------------------------------------------------------------------------- #
#  get_next_line (only the checker uses it)                                    #
# ---------------------------------------------------------------------------- #
#
# Only the mandatory files: the _bonus files define get_next_line too.
# BUFFER_SIZE can be changed: make checker BUFFER_SIZE=1

GNL_HEADER	= get_next_line.h
BUFFER_SIZE	?= 42

GNL_SRC		= get_next_line.c \
			  get_next_line_utils.c

# ---------------------------------------------------------------------------- #
#  Objects                                                                     #
# ---------------------------------------------------------------------------- #

MAIN_OBJ	= $(MAIN_SRC:.c=.o)
CHECKER_OBJ	= $(CHECKER_SRC:.c=.o)
OBJ			= $(SRC:.c=.o)
GNL_OBJ		= $(GNL_SRC:.c=.o)

# ---------------------------------------------------------------------------- #
#  Rules                                                                       #
# ---------------------------------------------------------------------------- #

all: $(NAME)

# push_swap = push_swap.o + the archive
$(NAME): $(MAIN_OBJ) $(LIB)
	$(CC) $(CFLAGS) $(MAIN_OBJ) $(LIB) -o $(NAME)

# checker: reads operations from stdin and prints OK / KO
# = checkers.o + the GNL objects + the same archive as push_swap
$(CHECKER): $(CHECKER_OBJ) $(GNL_OBJ) $(LIB)
	$(CC) $(CFLAGS) $(CHECKER_OBJ) $(GNL_OBJ) $(LIB) -o $(CHECKER)

bonus: $(CHECKER)

# "make main": same program, but written as push_swap.exe
main: $(MAIN_OBJ) $(LIB)
	$(CC) $(CFLAGS) $(MAIN_OBJ) $(LIB) -o push_swap

# one archive with every .o shared by push_swap and checker
$(LIB): $(OBJ)
	ar rcs $(LIB) $(OBJ)

# GNL objects: rebuilt when their .c or get_next_line.h changes
$(GNL_OBJ): %.o: %.c $(GNL_HEADER)
	$(CC) $(CFLAGS) -D BUFFER_SIZE=$(BUFFER_SIZE) $(INCLUDES) -c $< -o $@

# checkers.c includes both headers
$(CHECKER_OBJ): $(CHECKER_SRC) $(HEADER) $(GNL_HEADER)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

# everything else: rebuilt when its .c or pushswap.h changes
%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	rm -f $(MAIN_OBJ) $(CHECKER_OBJ) $(OBJ) $(GNL_OBJ)

fclean: clean
	rm -f $(NAME) $(EXE) $(CHECKER) $(LIB)

re: fclean all

.PHONY: all clean fclean re main bonus
