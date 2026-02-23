/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_pwd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grcharle <grcharle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 13:43:21 by grcharle          #+#    #+#             */
/*   Updated: 2026/02/23 14:28:53 by grcharle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/**
 * Command PWD
 */
char	*get_current_working_directory(void)
{
	char	*current_working_dir;

	current_working_dir = (char *) ft_calloc(sizeof(char), BUFFER_SIZE);
	if (!current_working_dir)
		return (perror(ERROR_X0), (char *) NULL);
	current_working_dir = getcwd(current_working_dir, (BUFFER_SIZE - 1));
	return (current_working_dir);
}
