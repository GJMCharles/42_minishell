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
	if (ms->command_line)
		free(ms->command_line);
}

/**
 * bool	setup_minishell(t_minishell *ms);
 */
bool	setup_minishell(t_minishell *ms)
{
	ms->newline = true;
	return (true);
}

t_key_info read_key_info() {
	t_key_info info = {0};
	unsigned char c;
	
	if (read(STDIN_FILENO, &c, 1) != 1)
	{
		info.name = "ERROR";
		return info;
	}

	info.sequence[0] = c;
	info.key_code = c;

	// Check for control characters
	if (c < 32)
	{
		info.is_ctrl = 1;
		if (c == 9)
			info.name = "TAB";
		else if (c >= 1 && c <= 26)
		{
			static const char* ctrl_names[] = {
				"CTRL+A", "CTRL+B", "CTRL+C", "CTRL+D", "CTRL+E",
				"CTRL+F", "CTRL+G", "CTRL+H", "CTRL+I", "CTRL+J",
				"CTRL+K", "CTRL+L", "CTRL+M", "CTRL+N", "CTRL+O",
				"CTRL+P", "CTRL+Q", "CTRL+R", "CTRL+S", "CTRL+T",
				"CTRL+U", "CTRL+V", "CTRL+W", "CTRL+X", "CTRL+Y",
				"CTRL+Z"
			};
			info.name = ctrl_names[c-1];
		}
		else if (c == 28)
			info.name = "CTRL+\\";
		return info;
	}
	// Check for ESC sequences (arrow keys)
	if (c == 27)
	{
		char seq[2];
		if (read(STDIN_FILENO, &seq[0], 1) == 1 && seq[0] == '[')
		{
			if (read(STDIN_FILENO, &seq[1], 1) == 1)
			{
				info.is_special = 1;
				info.is_arrow = 1;
				info.sequence[1] = seq[0];
				info.sequence[2] = seq[1];
				
				switch (seq[1]) {
					case 'A': info.name = "UP"; break;
					case 'B': info.name = "DOWN"; break;
					case 'C': info.name = "RIGHT"; break;
					case 'D': info.name = "LEFT"; break;
					default: info.name = "UNKNOWN_ESC";
				}
				return info;
			}
		}
		info.name = "ESC";
		return info;
	}
	// Regular character
	info.name = "REGULAR";
	return info;
}

/**
 * bool	display_prompt(t_minishell *ms);
 */
bool	display_prompt(t_minishell *ms)
{
	(void) ms;
	if (write(STDOUT_FILENO, "~$> ", 4) == -1)
		return (errno = EIO, perror("Error"), false);
	fetch_command_line(ms);
	if (ms->newline)
	{
		if (write(STDOUT_FILENO, "\n", 1) == -1)
			return (errno = EIO, perror("Error"), false);
		ms->newline = false;
	}
	return (true);
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
		if (!display_prompt(&ms))
			return (restore_mode(&mode), destroy_minishell(&ms), EXIT_FAILURE);
		

		//t_key_info key = read_key_info();
		//if (key.is_ctrl) {
		//	printf("Control: %s (ASCII %d)\n", key.name, key.key_code);
		//	set_signal_received(1);
		//} else if (key.is_arrow) {
		//	printf("Arrow: %s\n", key.name);
		//} else if (key.key_code == 27) {
		//	printf("ESC pressed - exiting\n");
		//	set_signal_received(1);
		//} else if (key.key_code == 9) {
		//	printf("TAB key\n");
		//} else if (ft_isprint(key.key_code)) {
		//	// ENABLE UTF-8
		//	printf("Normal: '%c' (ASCII %d)\n", key.key_code, key.key_code);
		//}
		break ;
	}
	restore_mode(&mode);
	destroy_minishell(&ms);
	return (true);
}

//bool	setup_minishell_requirements(t_minishell *ms)
//{
//	ms->add_newline = false;
//	ms->current_working_dir = NULL;
//	return (true);
//}
//	{
//		ms.current_command_line = get_input(&ms);
//		enable_interactive_mode(&ms);
//		// exec_commands(ms.current_command_line);
//		// append_command_line_to_history(ms.current_command_line);
//		free(ms.current_command_line);
//	}
//	return (true);
//}
