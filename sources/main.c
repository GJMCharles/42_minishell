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

void	handle_signal(int sig)
{
	ft_putstr_fd("# Signal Code ", STDOUT_FILENO);
	ft_putnbr_fd(sig, STDOUT_FILENO);
}

int	main(int argc, char *argv[], char *envp[])
{
	(void) argc;
	(void) argv;
	(void) envp;

	int		stdio;
	char	*command_line;

	stdio = STDOUT_FILENO;
	while (stdio == STDOUT_FILENO)
	{
		(void) write(STDOUT_FILENO, "~$> ", 4);
		command_line = get_input();
		stdio = minishell(command_line, envp);
		free(command_line);
	}
	if (stdio == STDERR_FILENO)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
