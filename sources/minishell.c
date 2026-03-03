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

bool	minishell(void)
{
	struct termios	mode;
	char			prompt[14];
	char			*command_line;

	if (!init_signals())
		return (perror("Error"), false);
	ft_strlcpy(prompt, "~[ 💻 ] $> ", 14);
	set_raw_mode(&mode);
	while (1)
	{
		command_line = get_command_line(prompt);
		// PARSE LINE
		if (command_line)
		{
			ft_putstr_fd(command_line, STDOUT_FILENO);
			free(command_line);
		}
		// EXECUTE COMMAND
		// EXECUTE SIGNAL
		// IF NO COMMAND && SIGNAL
		//  EXIT *(break)
		// return (restore_mode(&mode), free(prompt), false);
		break ;
	}
	restore_mode(&mode);
	ft_putendl_fd("\nexit", STDOUT_FILENO);
	return (true);
}
