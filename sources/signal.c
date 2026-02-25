/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grcharle <grcharle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 21:16:59 by grcharle          #+#    #+#             */
/*   Updated: 2026/02/23 21:17:18 by grcharle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

volatile sig_atomic_t g_signal_received = 0;

/**
 * void	set_signal_received(int sig);
 */
void	set_signal_received(int sig)
{
	g_signal_received = sig;
}

/**
 * int	get_signal_received(void);
 */
int	get_signal_received(void)
{
	return (g_signal_received);
}

/**
 * void	signal_handler(int sig);
 */
void	signal_handler(int sig)
{
	/**
	 * Because we are using `read` instead of `readline`
	 * it is nessecary to ignore the signal of `CTRL + C`
	 * Otherwise, the executable closes unexpectidaly
	 */
	(void) sig;
}

/**
 * bool	setup_signal_handler(void);
 */
bool	setup_signal_handler(void)
{
	struct sigaction	sa;

	ft_memset(&sa, 0, sizeof(sa));
	sa.sa_handler = signal_handler;
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = 0;
	if (sigaction(SIGINT, &sa, NULL) == -1)
		return (perror(ERROR_SS), false);
	return (true);
}
