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

int	main(int argc, char *argv[], char *envp[])
{
	(void) argv;
	verify_debug_mode_enabled();
	if (argc != 1)
		return (perror(ERROR_AG), EXIT_FAILURE);
	if (!setup_signal_handler())
		return (perror(ERROR_SS), EXIT_FAILURE);
	if (!minishell(envp))
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
