/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grcharle <grcharle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/02 20:09:49 by grcharle          #+#    #+#             */
/*   Updated: 2026/03/02 20:10:04 by grcharle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	main(int argc, char *argv[], char **envp)
{
	t_env	*env_list;

	(void) argc;
	(void) argv;
	env_list = setup_env_list(envp);
	if (!env_list)
		return (EXIT_FAILURE);

	destroy_env_list(&env_list);
	return (EXIT_SUCCESS);
}
