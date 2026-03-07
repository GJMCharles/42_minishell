/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grcharle <grcharle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/02 21:54:28 by grcharle          #+#    #+#             */
/*   Updated: 2026/03/02 21:54:38 by grcharle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "_signals.h"

volatile sig_atomic_t	g_exit_status = 0;

void	set_exit_status(int sig)
{
	g_exit_status = sig;
}

int	get_exit_status(void)
{
	return (g_exit_status);
}

int	setup_signals(void)
{
	struct sigaction sa;

	ft_memset(&sa, 0, sizeof(sa));
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = 0;
	sa.sa_sigaction = NULL;
	if (sigaction(SIGINT, &sa, NULL) == -1)
		return (0);
	return (1);
}
