# Makefile

# Directories
SRCDIR = src
INCDIR = include
LIBFTDIR = lib/libft

# Source files
SRCS = push_swap.c \
		list_manip.c \
		operations.c \
		errors_exit.c \
		algo.c

# Object files
OBJS = $(patsubst %.c, %.o, $(SRCS))

# Compiler
CC = gcc
CFLAGS = -Wall -Wextra -Werror -I$(INCDIR)

# Targets
NAME = push_swap

all: $(NAME)

$(NAME): $(OBJS)
	@$(MAKE) -C $(LIBFTDIR)
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJS) -L$(LIBFTDIR) -lft

%.o: $(SRCDIR)/%.c
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@$(MAKE) -C $(LIBFTDIR) clean
	@$(RM) $(OBJS)

fclean: clean
	@$(MAKE) -C $(LIBFTDIR) fclean
	@$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
