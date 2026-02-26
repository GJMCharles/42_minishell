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
#  define DEBUG 0
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

typedef unsigned int		t_ui;
typedef unsigned char		t_uc;
typedef unsigned long int	t_uli;

typedef struct s_debug
{
	bool		enabled;
}	t_debug;

typedef struct s_key_info
{
	bool		is_special;
	bool		is_ctrl;
	bool		is_arrow;
	bool		key_code;
	t_uc		sequence[4];
	const char*	name;
}	t_key_info;

typedef struct s_minishell
{
	char		*command_line;
	bool		newline;
	t_debug		debug;
}	t_minishell;

/**
 * input.c
 */
void	fetch_input(t_minishell *ms);

/**
 * termios.c
 */
void	restore_mode(struct termios *original);
void	set_raw_mode(struct termios *original);

/**
 * signal.c
 */
void	set_signal_received(int sig);
int		get_signal_received(void);
void	signal_handler(int sig);
bool	setup_signal(void);

/**
 * debug.c
 */
void	display_debug_error(char *message);
void	display_debug_info(char *message);
void	setup_debug(t_minishell *ms);

/**
 * minishell.c
 */
void	destroy_minishell(t_minishell *ms);
bool	setup_minishell(t_minishell *ms);
bool	display_prompt(t_minishell *ms);
bool	minishell(char *envp[]);

#endif
