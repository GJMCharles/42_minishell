/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grcharle <grcharle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/02 20:10:25 by grcharle          #+#    #+#             */
/*   Updated: 2026/03/02 20:10:38 by grcharle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	destroy_minishell(t_shell *minishell)
{
	destroy_env_list(&minishell->head_env);
	ft_putendl_fd("\nexit", STDOUT_FILENO);
}

int	execute_minishell(t_shell *minishell)
{
	(void) minishell;
	char		prompt[14];
	char		*command_line;

	ft_strlcpy(prompt, "~[ 💻 ] $> ", 14);
	while (get_exit_status() == 0)
	{
		command_line = readline(prompt);
		ft_putendl_fd(command_line, STDOUT_FILENO);
		free(command_line);
	}
	return (EXIT_SUCCESS);
}

int	setup_minishell(t_shell *minishell, char **envp)
{
	t_env		*head_env;

	head_env = setup_env_list(envp);
	if (!head_env)
		return (0);
	minishell->head_env = head_env;
	return (1);
}
