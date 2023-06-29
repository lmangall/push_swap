NAME = push_swap

SRCDIR = src
INCDIR = include
LIBFTDIR = lib/libft

SRCS = $(SRCDIR)/push_swap.c $(SRCDIR)/list_manip.c $(SRCDIR)/binary.c
OBJS = $(patsubst $(SRCDIR)/%.c, $(SRCDIR)/%.o, $(SRCS))

CC = gcc
CFLAGS = -Wall -Wextra -Werror -I$(INCDIR)

RM = rm -rf

all: $(NAME)

$(NAME): $(OBJS)
	@$(MAKE) -C $(LIBFTDIR)
	@$(CC) $(CFLAGS) $(OBJS) $(LIBFTDIR)/libft.a -o $(NAME)

$(SRCDIR)/%.o: $(SRCDIR)/%.c
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@$(MAKE) -C $(LIBFTDIR) clean
	@$(RM) $(OBJS)

fclean: clean
	@$(MAKE) -C $(LIBFTDIR) fclean
	@$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
