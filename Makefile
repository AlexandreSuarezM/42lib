# **************************************************************************** #
#                                  push_swap                                   #
# **************************************************************************** #
#
# How the build works:
#   1. Every .c below (except push_swap.c, which has main) is compiled to .o.
#   2. Those .o AND the ft_printf .o files are put into ONE archive:
#      push_swap.a. That way you never need a separate ft_printf.a.
#   3. push_swap.c is compiled and linked with push_swap.a to make the
#      program "push_swap" (the subject requires that executable name).
#
# No wildcards: every file is listed by hand, as 42 requires.

NAME		= push_swap
EXE			= push_swap.exe
CHECKER		= checker
LIB			= push_swap.a

CC			= cc
CFLAGS		= -Wall -Wextra -Werror
INCLUDES	= -I. -I$(PRINTF_DIR)

HEADER		= pushswap.h

# ---------------------------------------------------------------------------- #
#  Program sources                                                             #
# ---------------------------------------------------------------------------- #

MAIN_SRC	= push_swap.c
CHECKER_SRC	= checkers.c

UTILS_SRC	= utils/ft_atoi.c \
			  utils/ft_isdigit.c \
			  utils/ft_lstadd_top.c \
			  utils/ft_lstclear.c \
			  utils/ft_lstdelone.c \
			  utils/ft_lstnew.c \
			  utils/ft_lstsize.c \
			  utils/ft_split.c \
			  utils/ft_strcmp.c \
			  utils/ft_strlen.c \
			  utils/ft_substr.c \
			  utils/parse.c \
			  utils/get_next_line.c

#			  utils/ft_strlen.c    <- PLACEHOLDER: used by sorts/RadixSort.c,
#			                          only exists in deprecated/ right now
#			  utils/ft_substr.c    <- PLACEHOLDER: used by utils/ft_split.c,
#			                          does not exist yet

OPS_SRC		= Operations/push.c \
			  Operations/rotate.c \
			  Operations/rotateup.c \
			  Operations/sabs.c \
			  Operations/op_log.c

SORTS_SRC	= sorts/disorder.c \
			  sorts/RadixSort.c \
			  sorts/selectionsort.c \
			  sorts/chunking.c \
			  sorts/adaptive.c

BENCH_SRC	= bench.c

DEBUG_SRC	= showlist.c

SRC			= $(UTILS_SRC) $(OPS_SRC) $(SORTS_SRC) $(BENCH_SRC) $(DEBUG_SRC)

# ---------------------------------------------------------------------------- #
#  ft_printf (PLACEHOLDER)                                                     #
# ---------------------------------------------------------------------------- #
#
# Copy your ft_printf folder into this repo (e.g. ./ft_printf/) and list its
# .c files below. They are compiled with the same rule as everything else and
# their .o go straight into push_swap.a, so there is no ft_printf.a.
#
# - PRINTF_DIR: folder with the ft_printf .c files and its header
#   (e.g. ft_printf.h). It is added to INCLUDES with -I so pushswap.h can do
#   #include "ft_printf.h".
# - If ft_printf.h uses va_list, it must #include <stdarg.h> itself.
# - Each ft_printf .o depends on its own .c and on the ft_printf header,
#   see the $(PRINTF_DIR)/%.o rule below.

PRINTF_DIR		= ft_printf
PRINTF_HEADER	= $(PRINTF_DIR)/ft_printf.h

PRINTF_SRC		=
#PRINTF_SRC		= $(PRINTF_DIR)/ft_printf.c \
#				  $(PRINTF_DIR)/ft_conv.c \
#				  $(PRINTF_DIR)/ft_putcharc.c \
#				  $(PRINTF_DIR)/ft_putstr.c \
#				  $(PRINTF_DIR)/ft_putnbr_signed.c \
#				  $(PRINTF_DIR)/ft_putnbr_unsigned.c \
#				  $(PRINTF_DIR)/ft_hextoa.c \
#				  $(PRINTF_DIR)/ft_hextoa_upper.c \
#				  $(PRINTF_DIR)/ft_pointtoa.c
#				  ^ replace these with the real file names from your ft_printf

# ---------------------------------------------------------------------------- #
#  Objects                                                                     #
# ---------------------------------------------------------------------------- #

MAIN_OBJ	= $(MAIN_SRC:.c=.o)
CHECKER_OBJ	= $(CHECKER_SRC:.c=.o)
OBJ			= $(SRC:.c=.o)
PRINTF_OBJ	= $(PRINTF_SRC:.c=.o)

# ---------------------------------------------------------------------------- #
#  Rules                                                                       #
# ---------------------------------------------------------------------------- #

all: $(NAME)

# Final program: main + the archive.
$(NAME): $(MAIN_OBJ) $(LIB)
	$(CC) $(CFLAGS) $(MAIN_OBJ) $(LIB) -o $(NAME)

# "make main": same program, but written as push_swap.exe
# checker: reads operations from stdin and prints OK / KO
$(CHECKER): $(CHECKER_OBJ) $(LIB)
	$(CC) $(CFLAGS) $(CHECKER_OBJ) $(LIB) -o $(CHECKER)

bonus: $(CHECKER)

main: $(MAIN_OBJ) $(LIB)
	$(CC) $(CFLAGS) $(MAIN_OBJ) $(LIB) -o $(EXE)

# One archive with your .o and the ft_printf .o together.
$(LIB): $(OBJ) $(PRINTF_OBJ)
	ar rcs $(LIB) $(OBJ) $(PRINTF_OBJ)

# ft_printf objects: rebuilt when their .c or the ft_printf header changes.
$(PRINTF_DIR)/%.o: $(PRINTF_DIR)/%.c $(PRINTF_HEADER)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

# Everything else: rebuilt when its .c or pushswap.h changes.
%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	rm -f $(MAIN_OBJ) $(CHECKER_OBJ) $(OBJ) $(PRINTF_OBJ)

fclean: clean
	rm -f $(NAME) $(EXE) $(CHECKER) $(LIB)

re: fclean all

.PHONY: all clean fclean re main bonus
