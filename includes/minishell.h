/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grcharle <grcharle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/02 20:19:51 by grcharle          #+#    #+#             */
/*   Updated: 2026/03/02 20:20:17 by grcharle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# ifndef DEBUG
#  define DEBUG false
# endif

# ifndef _GNU_SOURCE
#  define _GNU_SOURCE
# endif

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# endif

# include "libft.h"
# include <stdlib.h>
# include <unistd.h>
# include <stdbool.h>
# include <stdio.h>
# include <signal.h>
# include <termios.h>

extern volatile sig_atomic_t	g_exit_status;

typedef unsigned long int	t_uli;
typedef unsigned int		t_ui;
typedef unsigned char		t_uc;

typedef struct s_keycode
{
	t_ui	test;
}	t_keycode;

typedef struct s_history
{
	t_ui	test;
}	t_history;

typedef struct s_env
{
	char			*key;
	char			*value;
	struct s_env	*next;
}	t_env;

typedef struct s_shell
{
	struct s_history	history;
	struct s_env		env;
}	t_shell;

/**
 * command_line.c
 */
char		*get_command_line(char *prompt);

/**
 * debug.c
 */


/**
 * minishell.c
 */
bool		minishell(void);

/**
 * signal.c
 */
void		set_exit_status(int sig);
int			get_exit_status(void);
bool		init_signals(void);

/**
 * termios.c
 */
void		restore_mode(struct termios *original);
void		set_raw_mode(struct termios *original);

#endif
