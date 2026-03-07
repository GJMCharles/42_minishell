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

# include "libft.h"
# include "_env.h"
# include <stdlib.h>
# include <unistd.h>
# include <stdbool.h>
# include <stdio.h>
# include <signal.h>

extern volatile sig_atomic_t	g_exit_status;

typedef unsigned long int	t_uli;
typedef unsigned int		t_ui;
typedef unsigned char		t_uc;

#endif
