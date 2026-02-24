/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchanteu <bchanteu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 15:02:08 by bchanteu          #+#    #+#             */
/*   Updated: 2025/11/28 15:54:37 by bchanteu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# ifndef _GNU_SOURCE
#  define _GNU_SOURCE
# endif

# include <signal.h>
# include <stdbool.h>
# include <stdio.h>
# include <termios.h>
# include "libft.h"

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 512
# endif

# define ERROR_XS "failed to initiate `sigaction`"
# define ERROR_X0 "failed to allocate memory"
# define ERROR_X1 "failed to read standard input"
# define ERROR_XA "failed to write standard output"
# define ERROR_X2 "an unexpected error has occured"
# define ERROR_X3 ""

typedef unsigned long int	uli;

typedef enum {
	KEY_NORMAL,
	KEY_ESC, KEY_TAB,
	KEY_UP, KEY_DOWN, KEY_LEFT, KEY_RIGHT,
	KEY_CTRL_A, KEY_CTRL_B, KEY_CTRL_C, KEY_CTRL_D,
	KEY_CTRL_E, KEY_CTRL_F, KEY_CTRL_G, KEY_CTRL_H,
	KEY_CTRL_I, KEY_CTRL_J, KEY_CTRL_K, KEY_CTRL_L,
	KEY_CTRL_M, KEY_CTRL_N, KEY_CTRL_O, KEY_CTRL_P,
	KEY_CTRL_Q, KEY_CTRL_R, KEY_CTRL_S, KEY_CTRL_T,
	KEY_CTRL_U, KEY_CTRL_V, KEY_CTRL_W, KEY_CTRL_X,
	KEY_CTRL_Y, KEY_CTRL_Z, KEY_CTRL_BACKSLASH,
	KEY_ENTER, KEY_UNKNOWN
} e_keycode;

typedef struct s_history
{
	uli					id;
	char				*line;
} t_history;

typedef struct s_minishell
{
	char	*current_working_dir;
	char	**commands;
}	t_minishell;

/**
 * command_line.c
 */
char	**get_command_lines(char *command_line);

/**
 * cmd_pwd.c
 */
char	*set_command_pwd(char **command_line);

/**
 * history.c
 */
void		print_history(t_history *list);
void		clear_history(t_history **list);
void		update_history(char *command_line);

/**
 * minishell.c
 */
void		clear_minishell_data(t_minishell *data);
int			minishell(char *command_line, char *envp[]);

/**
 * input.c
 */
e_keycode	read_key(void);
e_keycode	get_input(char **input);

/**
 * stdin_mode.c
 */
void		set_raw_mode(struct termios *original);
void		restore_mode(struct termios *original);

/**
 * signal.c
 */
void		set_signal_received(int sig);
int			get_signal_received(void);
void		signal_handler(int sig);
bool		setup_signal_handlers(void);

#endif
