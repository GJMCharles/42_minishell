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

t_env	*init_env(char **envp)
{
	t_env	*env;

	env = (t_env *) ft_calloc(sizeof(t_env), 1);
	if (!env)
		return (NULL);
}

int	main(int argc, char *argv[], char **envp)
{
	t_env		*env;
	t_history	*history;
	t_shell		*shell;

	(void) argc;
	(void) argv;
	env = init_env(envp);
	history = init_history();
	shell = init_shell(env, history);
	minishell(shell);
	destroy_history(&history);
	destroy_env(&env);
	destroy_shell(&shell);
	return (EXIT_SUCCESS);
}
