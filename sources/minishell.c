/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grcharle <grcharle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 14:21:36 by grcharle          #+#    #+#             */
/*   Updated: 2026/02/28 00:00:00 by grcharle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	clear_env(t_env **env)
{
	t_env	*cur;
	t_env	*next;

	cur = *env;
	while (cur)
	{
		next = cur->next;
		free(cur->key);
		free(cur->value);
		free(cur);
		cur = next;
	}
	*env = NULL;
}

void	destroy_minishell(t_minishell *ms)
{
	clear_env(&ms->env);
	free(ms->command_line);
}

bool	setup_minishell(t_minishell *ms, char *envp[])
{
	ms->newline = true;
	ms->command_line = NULL;
	ms->env = NULL;
	if (env_from_envp(&ms->env, envp))
		return (false);
	ms->input.is_arrow = false;
	ms->input.is_ctrl = false;
	ms->input.is_special = false;
	ft_bzero(ms->input.utf8_char, 4);
	ms->input.keycode = KEY_UNKNOWN;
	return (true);
}

bool	custom_prompt(t_minishell *ms)
{
	if (write(STDOUT_FILENO, "~$> ", 4) == -1)
		return (errno = EIO, perror("Error"), false);
	fetch_input(ms);
	if (ms->newline)
	{
		if (write(STDOUT_FILENO, "\n", 1) == -1)
			return (errno = EIO, perror("Error"), false);
	}
	return (true);
}

bool	minishell(char *envp[])
{
	t_minishell		ms;
	struct termios	mode;

	setup_debug(&ms);
	if (!setup_signal())
		return (errno = EINTR, perror("Error"), false);
	if (!setup_minishell(&ms, envp))
		return (errno = EPERM, perror("Error"), false);
	set_raw_mode(&mode);
	while (get_signal_received() == 0)
	{
		if (!custom_prompt(&ms))
			return (restore_mode(&mode), destroy_minishell(&ms), false);
		if (ms.input.keycode == KEY_CTRL_D)
			set_signal_received(1);
		free(ms.command_line);
	}
	restore_mode(&mode);
	destroy_minishell(&ms);
	return (true);
}
