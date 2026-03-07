/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grcharle <grcharle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/02 20:09:49 by grcharle          #+#    #+#             */
/*   Updated: 2026/03/07 13:59:15 by grcharle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/**
 * int	main(int argc, char *argv[], char **envp);
 */
int	main(int argc, char *argv[], char **envp)
{
	t_shell		minishell;
	int			status;

	(void) argc;
	(void) argv;
	if (!setup_minishell(&minishell, envp))
		return (EXIT_FAILURE);
	status = execute_minishell(&minishell);
	destroy_minishell(&minishell);
	return (status);
}
