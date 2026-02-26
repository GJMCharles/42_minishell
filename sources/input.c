/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grcharle <grcharle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/26 15:26:03 by grcharle          #+#    #+#             */
/*   Updated: 2026/02/26 15:31:28 by grcharle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	fetch_command_line(t_minishell *ms)
{
	char	*command_line;

	ms->command_line = NULL;
	command_line = (char *) ft_calloc(sizeof(char), 1);
	if (!command_line)
		return ;
	free(command_line);
}
