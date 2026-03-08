/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_list.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grcharle <grcharle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/08 00:01:33 by grcharle          #+#    #+#             */
/*   Updated: 2026/03/08 00:01:35 by grcharle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "_command.h"

t_pipe  *parse_token(t_token *tokens)
{
	t_pipe	*pipe;
	t_cmd			*cmd;

	(void) tokens;
	init_command_pipeline(&pipe, &cmd);

	free(pipe->commands);
	free(pipe->operators);
	free(pipe);
	free(cmd->args);
	free(cmd);
	return (NULL);
}

void	*init_command_pipeline(t_pipe **pipe, t_cmd **cmd)
{
	*pipe = NULL;
	*cmd = NULL;
	// *pipe
	*pipe = (t_pipe *) ft_calloc(sizeof(t_pipe), 1);
	if (!*pipe)
		return (perror("failed to allocate 'struct s_pipe'"), NULL);
	// (*pipe)->commands
	(*pipe)->commands = (t_cmd **) ft_calloc(sizeof(t_cmd *), 1);
	if (!(*pipe)->commands)
		return (perror("failed to allocate 'struct s_cmd **'"), free(*pipe), NULL);
	// (*pipe)->operators
	(*pipe)->operators = (int *) ft_calloc(sizeof(int), 1);
	if (!(*pipe)->operators)
		return (perror("failed to allocate 'int *'"), free((*pipe)->commands), free(pipe), NULL);
	// *cmd
	*cmd = (t_cmd *) ft_calloc(sizeof(t_cmd), 1);
	if (!*cmd)
		return (perror("failed to allocate 'struct s_cmd'"), free((*pipe)->operators), free((*pipe)->commands), free(*pipe), NULL);
	// (*cmd)->args
	(*cmd)->args = (char **) ft_calloc(sizeof(char *), 1);
	if (!(*cmd)->args)
		return (perror("failed to allocate 'char **'"), free((*pipe)->operators), free((*pipe)->commands), free(*pipe), free(*cmd), NULL);
	return (NULL);
}
