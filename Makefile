# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lmangall <lmangall@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/09 18:29:39 by lmangall          #+#    #+#              #
#    Updated: 2023/07/09 18:48:04 by lmangall         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Makefile

# Directories
SRCDIR = src
INCDIR = include
LIBFTDIR = lib/libft

# Source files
SRCS = main_ini_assign.c \
		list_manip.c \
		operations_main.c \
		operations_redirect.c \
		checks_errors_exit.c \
		free.c \
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
	@$(RM) $(OBJS) $(NAME).o

fclean: clean
	@$(MAKE) -C $(LIBFTDIR) fclean
	@$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
