/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _signals.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grcharle <grcharle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/07 14:02:52 by grcharle          #+#    #+#             */
/*   Updated: 2026/03/07 14:02:53 by grcharle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _SIGNALS_H
# define _SIGNALS_H

# ifndef _GNU_SOURCE
#  define _GNU_SOURCE
# endif

# include "libft.h"
# include <signal.h>

extern volatile sig_atomic_t	g_exit_status;

void		set_exit_status(int sig);
int			get_exit_status(void);
int			setup_signals(void);

#endif
