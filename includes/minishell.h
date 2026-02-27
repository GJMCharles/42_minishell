/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grcharle <grcharle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/26 11:59:22 by grcharle          #+#    #+#             */
/*   Updated: 2026/02/26 11:59:25 by grcharle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# ifndef _GNU_SOURCE
#  define _GNU_SOURCE
# endif

# ifndef DEBUG
#  define DEBUG false
# endif

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# endif

//# define ERROR_AG "no arguments required"
//# define ERROR_MA "failed to allocate memory"
//# define ERROR_MS "failed to setup minishell"
//# define ERROR_RI "failed to read standard input"
//# define ERROR_SS "failed to initiate 'sigaction'"
//# define ERROR_WO "failed to write standard output"
//# define ERROR_XX "an unexpected error has occured"

# include "libft.h"
# include <stdbool.h>
# include <signal.h>
# include <stdio.h>
# include <errno.h>
# include <termios.h>

# define enum_str(x) #x
# define xenum_str(x) enum_str(x)

# define FOREACH_KEYCODE(KEYCODE)	\
	KEYCODE(KEY_NORMAL)				\
	KEYCODE(KEY_ENTER)				\
	KEYCODE(KEY_ESC)				\
	KEYCODE(KEY_TAB)				\
	KEYCODE(KEY_UP)					\
	KEYCODE(KEY_DOWN)				\
	KEYCODE(KEY_RIGHT)				\
	KEYCODE(KEY_LEFT)				\
	KEYCODE(KEY_CTRL_A)				\
	KEYCODE(KEY_CTRL_B)				\
	KEYCODE(KEY_CTRL_C)				\
	KEYCODE(KEY_CTRL_D)				\
	KEYCODE(KEY_CTRL_E)				\
	KEYCODE(KEY_CTRL_F)				\
	KEYCODE(KEY_CTRL_G)				\
	KEYCODE(KEY_CTRL_H)				\
	KEYCODE(KEY_CTRL_I)				\
	KEYCODE(KEY_CTRL_J)				\
	KEYCODE(KEY_CTRL_K)				\
	KEYCODE(KEY_CTRL_L)				\
	KEYCODE(KEY_CTRL_M)				\
	KEYCODE(KEY_CTRL_N)				\
	KEYCODE(KEY_CTRL_O)				\
	KEYCODE(KEY_CTRL_P)				\
	KEYCODE(KEY_CTRL_Q)				\
	KEYCODE(KEY_CTRL_R)				\
	KEYCODE(KEY_CTRL_S)				\
	KEYCODE(KEY_CTRL_T)				\
	KEYCODE(KEY_CTRL_U)				\
	KEYCODE(KEY_CTRL_V)				\
	KEYCODE(KEY_CTRL_W)				\
	KEYCODE(KEY_CTRL_X)				\
	KEYCODE(KEY_CTRL_Y)				\
	KEYCODE(KEY_CTRL_Z)				\
	KEYCODE(KEY_CTRL_BACKSLASH)		\
	KEYCODE(KEY_UNKNOWN)

# define GENERATE_ENUM(ENUM) ENUM,
# define GENERATE_STRING(STRING) #STRING,

typedef enum e_keycode {
	FOREACH_KEYCODE(GENERATE_ENUM)
}	t_keycode;

//static const char *KEYCODE_STRING[] = {
//	FOREACH_KEYCODE(GENERATE_STRING)
//};

typedef unsigned int		t_ui;
typedef unsigned char		t_uc;
typedef unsigned long int	t_uli;

typedef struct s_input
{
	bool		is_arrow;
	bool		is_ctrl;
	bool		is_special;
	t_uc		utf8_char[4];
	t_keycode	keycode;
}	t_input;

typedef struct s_utf8_char
{
	t_ui		bytes;
	t_ui		needed;
	t_uc		utf8_char[4];
	t_ui		size;
	int			status;
}	t_utf8_char;

typedef struct s_debug
{
	bool		enabled;
}	t_debug;

typedef struct s_minishell
{
	bool		newline;
	char		*command_line;
	t_input		input;
	t_debug		debug;
}	t_minishell;

/**
 * input_keycode.c
 */
void		ctrl_to_keycode(t_input *input, t_uc *c);
void		append_to_keycode(t_input *input, t_uc *c, t_keycode keycode);
void		arrow_to_keycode(t_input *input, t_uc *c);
void		get_keycode(t_uc *c, t_input *input);

/**
 * input_utf8.c
 */
int			parse_utf8_char(t_uc c, t_uc **buffer, t_utf8_char *state);
t_ui		utf8_len(t_uc c);
t_uc		*get_utf8_char(void);

/**
 * input.c
 */
void		clear_input(t_input *input);
bool		can_exit_input(t_keycode keycode);
void		fetch_input(t_minishell *ms);

/**
 * termios.c
 */
void		restore_mode(struct termios *original);
void		set_raw_mode(struct termios *original);

/**
 * signal.c
 */
void		set_signal_received(int sig);
int			get_signal_received(void);
void		signal_handler(int sig);
bool		setup_signal(void);

/**
 * debug.c
 */
void		display_debug_error(char *message);
void		display_debug_info(char *message);
void		setup_debug(t_minishell *ms);

/**
 * minishell.c
 */
void		destroy_minishell(t_minishell *ms);
bool		setup_minishell(t_minishell *ms);
bool		custom_prompt(t_minishell *ms);
bool		minishell(char *envp[]);

#endif
