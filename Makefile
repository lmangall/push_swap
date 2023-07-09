# Makefile

# Directories
SRCDIR = src
INCDIR = include
LIBFTDIR = lib/libft

# Source files
SRCS = main_ini_assign.c \
		list_manip.c \
		operations.c \
		checks_errors_exit.c \
		algo.c \
		utils.c \
		algo_utils.c

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
