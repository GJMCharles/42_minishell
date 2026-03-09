/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grcharle <grcharle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/02 20:10:25 by grcharle          #+#    #+#             */
/*   Updated: 2026/03/07 13:59:02 by grcharle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/**
 * void	destroy_minishell(t_shell *minishell);
 */
void	destroy_minishell(t_shell *minishell)
{
	destroy_env_list(&minishell->head_env);
	ft_putendl_fd("\nexit", STDOUT_FILENO);
}

/**
 * int	execute_minishell(t_shell *minishell);
 */
int	execute_minishell(t_shell *minishell)
{
	char	prompt[14];

	ft_strlcpy(prompt, "~[ 💻 ] $> ", 14);
	while (get_exit_status() == 0)
	{
		//line = readline(prompt);
		// TEST
		minishell->line = ft_strdup("      echo -e \"TEST 1 2 3\" && ls -lah ;; pwd || echo \'Yes, I am here 😜\'");
		minishell->token_list = tokenize(minishell->line);
		free(minishell->line);
		minishell->pipeline = build_commands_pipeline(minishell->token_list);
		destroy_token_list(&minishell->token_list);
		// execute_pipeline(minishell->pipeline);
		destroy_command_pipeline(&minishell->pipeline);
		break ;
	}
	return (EXIT_SUCCESS);
}

/**
 * int	setup_minishell(t_shell *minishell, char **envp);
 */
int	setup_minishell(t_shell *minishell, char **envp)
{
	t_env		*head_env;

	head_env = setup_env_list(envp);
	if (!head_env)
		return (0);
	minishell->head_env = head_env;
	return (1);
}
