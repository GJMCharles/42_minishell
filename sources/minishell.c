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

/**
 * void	destroy_minishell(t_minishell *ms);
 */
void	destroy_minishell(t_minishell *ms)
{
	(void) ms;
}

/**
 * bool	setup_minishell(t_minishell *ms);
 */
bool	setup_minishell(t_minishell *ms)
{
	ms->newline = true;
	ms->command_line = NULL;
	ms->input.is_arrow = false;
	ms->input.is_ctrl = false;
	ms->input.is_special = false;
	ft_bzero(ms->input.utf8_char, 4);
	ms->input.keycode = KEY_UNKNOWN;
	return (true);
}

/**
 * bool	custom_prompt(t_minishell *ms);
 */
bool	custom_prompt(t_minishell *ms)
{
	(void) ms;
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

void	interactive_mode(t_minishell *shell)
{
	if (shell->input.keycode == KEY_CTRL_D)
		set_signal_received(1);
}

/**
 * bool	minishell(char *envp[]);
 */
bool	minishell(char *envp[])
{
	t_minishell		ms;
	struct termios	mode;

	(void) envp;
	setup_debug(&ms);
	if (!setup_signal())
		return (errno = EINTR, perror("Error"), false);
	if (!setup_minishell(&ms))
		return (errno = EPERM, perror("Error"), false);
	set_raw_mode(&mode);
	while (get_signal_received() == 0)
	{
		if (!custom_prompt(&ms))
			return (restore_mode(&mode), destroy_minishell(&ms), EXIT_FAILURE);
		interactive_mode(&ms);
		free(ms.command_line);
	}
	restore_mode(&mode);
	destroy_minishell(&ms);
	return (true);
}
