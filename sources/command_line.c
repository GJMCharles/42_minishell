/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_line.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grcharle <grcharle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 14:27:51 by grcharle          #+#    #+#             */
/*   Updated: 2026/02/23 14:29:03 by grcharle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	**get_command_lines(char *command_line)
{
	char	**lines;
	uli		nb_split;

	lines = ft_split(command_line, ';');
	nb_split = 0;
	if (!lines)
		return ((char **) NULL);
	while (lines++)
	{
		printf("@ %s\n", *lines);
	}
	free(lines);
	return (lines);
}
