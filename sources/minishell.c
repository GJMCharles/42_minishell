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
	if (data->current_working_dir)
		free(data->current_working_dir);
}

int	minishell(char *command_line, char *envp[])
{
	(void) command_line;
	t_minishell	data;

	(void) data;
	(void) envp;
	if (!set_command_pwd(&data.current_working_dir))
		return (clear_minishell_data(&data), STDERR_FILENO);
	ft_putstr_fd("Command `pwd`: ", STDOUT_FILENO);
	ft_putstr_fd(data.current_working_dir, STDOUT_FILENO);
	ft_putstr_fd("\n", STDOUT_FILENO);
	return (1);
}
