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
char	*get_command_pwd(void)
{
	char	*data;

	data = (char *) ft_calloc(sizeof(char), BUFFER_SIZE);
	if (!data)
		return (perror(ERROR_MA), NULL);
	data = getcwd(data, (BUFFER_SIZE - 1));
	return (data);
}
