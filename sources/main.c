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

/**
 * main.c
 */
int	main(int argc, char *argv[], char *envp[])
{
	(void) argv;
	if (argc != 1)
		return (errno = E2BIG, perror("Error"), EXIT_FAILURE);
	if (!minishell(envp))
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
