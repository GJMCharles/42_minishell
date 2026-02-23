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

void	clear_minishell_data(t_minishell *data)
{
	uli		index;

	index = 0;
	if (data->current_path)
		free(data->current_path);
	if (data->commands)
	{
		while (data->commands[index] != NULL)
		{
			free(data->commands[index]);
			index += 1;
		}
		free(data->commands);
	}
}

int	minishell(char *command_line, char *envp[])
{
	t_minishell	data;

	(void) envp;
	data.current_path = get_current_working_directory();
	if (!data.current_path)
		return (clear_minishell_data(&data), -1);
	data.commands = get_command_lines(command_line);
	if (!data.commands)
		return (clear_minishell_data(&data), -1);
	// update_history(command_line);
	clear_minishell_data(&data);
	return (STDERR_FILENO);
}
