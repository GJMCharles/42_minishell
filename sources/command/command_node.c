/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_node.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grcharle <grcharle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/08 00:01:39 by grcharle          #+#    #+#             */
/*   Updated: 2026/03/08 00:01:41 by grcharle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "_command.h"

void	destroy_command(t_cmd **cmd)
{
	t_cmd	*tmp_cmd;
	int		i;

	tmp_cmd = *cmd;
	if (tmp_cmd)
	{
		i = 0;
		while (i < tmp_cmd->argc)
		{
			if (tmp_cmd->args && tmp_cmd->args[i])
				free(tmp_cmd->args[i]);
			i += 1;
		}
		free(tmp_cmd->args);
		free(tmp_cmd);
	}
	tmp_cmd = NULL;
}

int	create_command(t_cmd **cmd, size_t max_length)
{
	t_cmd	*tmp_cmd;

	*cmd = NULL;
	tmp_cmd = (t_cmd *) ft_calloc(sizeof(t_cmd), 1);
	if (!tmp_cmd)
		return (perror("failed to allocate 'struct s_cmd'"), 0);
	tmp_cmd->args = (char **) ft_calloc(sizeof(char *), max_length + 1);
	if (!tmp_cmd->args)
	{
		destroy_command(&tmp_cmd);
		return (perror("failed to allocate 'char *'"), 0);
	}
	tmp_cmd->argc = 0;
	tmp_cmd->infile = NULL;
	tmp_cmd->outfile = NULL;
	tmp_cmd->heredoc_delimiter = NULL;
	tmp_cmd->append_mode = 0;
	tmp_cmd->background = 0;
	*cmd = tmp_cmd;
	return (1);
}
