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
	// char		prompt[14];
	// char		*command_line;

	// ft_strlcpy(prompt, "~[ 💻 ] $> ", 14);
	while (1)
	{
		// command_line = get_command_line(prompt);
		// PARSE LINE
		// if (command_line)
		// {
			// ft_putstr_fd(command_line, STDOUT_FILENO);
			// free(command_line);
		// }
		// EXECUTE COMMAND
		// EXECUTE SIGNAL
		// IF NO COMMAND && SIGNAL
		//  EXIT *(break)
		// return (restore_mode(&mode), free(prompt), false);
		break ;
	}
	return (EXIT_SUCCESS);
}

bool	setup_minishell(t_shell *minishell, char **envp)
{
	t_env		*head_env;
	t_shell		*minishell;

	head_env = setup_env_list(envp);
	if (!head_env)
		return (false);
	minishell->head_env = head_env;
	return (true);
}
