/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grcharle <grcharle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 14:21:36 by grcharle          #+#    #+#             */
/*   Updated: 2026/02/23 14:21:47 by grcharle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

bool	setup_minishell_requirements(t_minishell *ms)
{
	ms->add_newline = false;
	ms->current_working_dir = NULL;
	return (true);
}

int	minishell(char *envp[])
{
	t_minishell	ms;

	(void) envp;
	if (!setup_minishell_requirements(&ms))
		return (perror(ERROR_MS), false);
	while (get_signal_received() == 0)
	{
		if (write(STDOUT_FILENO, "~$> ", 4) == -1)
			return (perror(ERROR_WO), false);
		ms.current_command_line = get_input(&ms);
		enable_interactive_mode(&ms);
		if (ms.add_newline)
		{
			if (write(STDOUT_FILENO, "\n", 1) == -1)
				return (perror(ERROR_WO), false);
			ms.add_newline = false;
		}
		free(ms.current_command_line);
	}
	return (true);
}
