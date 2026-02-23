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

# include <stdio.h>
# include <signal.h>
# include "libft.h"

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 512
# endif

# define ERROR_X0 "failed to allocate memory"
# define ERROR_X1 "failed to read standard input"
# define ERROR_X2 "an unexpected error has occured"
# define ERROR_X3 ""

typedef unsigned long int	uli;

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
void			update_history(char *command_line);

/**
 * input.c
 */
char		*get_input(void);

/**
 * minishell.c
 */
void		clear_minishell_data(t_minishell *data);
int			minishell(char *command_line, char *envp[]);

#endif
