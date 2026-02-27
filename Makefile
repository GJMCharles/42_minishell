# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bchanteu <bchanteu@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/11/28 15:01:10 by bchanteu          #+#    #+#              #
#    Updated: 2025/11/28 15:05:41 by bchanteu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Set default rule when 'make all'
.DEFAULT_GOAL := all

# Hide message 'Entering directory' & 'Leaving directory'
MAKEFLAGS += --no-print-directory

CC := cc
CFLAGS := \
	-Wall -Wextra -Werror \
	-Wpedantic -Wformat -Wformat-security \
	-Wstack-protector -Wstrict-overflow=5 \
	-D_FORTIFY_SOURCE=2 -fstack-protector-strong \
	-fno-omit-frame-pointer \
	-fPIE -fPIC -O2 -g3

# Delete files & empty directories
RM := rm -f -v
RM_DIR := rmdir -v

NAME := minishell

LIBRARY := ./includes
SOURCES := ./sources

# Project Libft (+GetNextLine/+FtPrintF)
LIBFT := $(addprefix $(LIBRARY)/, libft)

CPPFLAGS := \
-I $(LIBRARY) \
-I $(LIBFT)

# Specifies options for the linker:
# example: -L/usr/local/lib
LDFLAGS := \
-L $(LIBFT)

# Lists libraries to link with:
# example: -lm -lpthread
LDLIBS := \
-lft

SOURCES_MANDATORY := \
	main.c \
	minishell.c \
	debug.c \
	signal.c \
	termios.c \
	input.c \
	input_utf8.c \
	input_keycode.c

OBJECTS_MANDATORY := $(patsubst $(SOURCES)/%.c, \
	.objects/%.o, \
	$(addprefix $(SOURCES)/, $(SOURCES_MANDATORY)) \
)

DEPENDENCIES_MANDATORY :=

-include $(DEPENDENCIES_MANDATORY)

OBJECTS_DIR := .objects

DEBUG := -D DEBUG=1

$(OBJECTS_DIR):
	mkdir -p $@

$(OBJECTS_DIR)/%.o: $(SOURCES)/%.c | $(OBJECTS_DIR)
	$(CC) $(CFLAGS) $(CPPFLAGS) $(DEBUG) -c $< -o $@

$(NAME): $(OBJECTS_MANDATORY)
	@$(MAKE) -C $(LIBFT) all
	$(CC) $(CFLAGS) $^ -o $@ $(LDFLAGS) $(LDLIBS)

all: $(NAME)

clean:
	@$(MAKE) -C $(LIBFT) clean
	@$(RM) $(OBJECTS_MANDATORY)

fclean: clean
	@$(MAKE) -C $(LIBFT) fclean
	@if [ -d  $(OBJECTS_DIR) ]; then \
		$(RM_DIR) -p $(OBJECTS_DIR); \
	fi
	@$(RM) $(NAME)

re: fclean all

debug: re
	-valgrind --leak-check=full --show-leak-kinds=all --trace-children=yes --track-origins=yes --suppressions=readline.supp -s ./$(NAME)

norm:
	-norminette -R $(shell find ./includes -type f -name "*.h")
	-norminette -R $(shell find ./sources -type f -name "*.c")

.PHONY: all clean fclean re
