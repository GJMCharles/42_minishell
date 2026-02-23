/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grcharle <grcharle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/22 17:24:35 by grcharle          #+#    #+#             */
/*   Updated: 2026/02/22 17:24:37 by grcharle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

volatile sig_atomic_t g_flag = 0;

void	signal_handler(int sig)
{
	/**
	 * Because we are using `read` instead of `readline`
	 * it is nessecary to ignore the signal of `CTRL + C`
	 * Otherwise, the executable closes unexpectidaly
	 */
	(void) sig;
	// g_flag = sig;
}

bool	init_signal(struct sigaction sa)
{
	sa.sa_handler = signal_handler;
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = 0;
	if (sigaction(SIGINT, &sa, NULL) == -1)
		return (perror(ERROR_XS), false);
	return (true);
}

int	main(int argc, char *argv[], char *envp[])
{
	(void) argc;
	(void) argv;
	(void) envp;

	struct sigaction sa;

	int		output_status;
	char	*command_line;

	ft_memset(&sa, 0, sizeof(sa));
	if (!init_signal(sa))
		return (perror(ERROR_XS), EXIT_FAILURE);
	output_status = 0;
	while (!output_status)
	{
		(void) write(STDOUT_FILENO, "~$> ", 4);
		command_line = get_input();
		// ft_putstr_fd(command_line, STDOUT_FILENO);
		// output_status = minishell(command_line, envp);
		ft_putstr_fd("\n", STDOUT_FILENO);
		free(command_line);
	}
	if (output_status == STDERR_FILENO)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
