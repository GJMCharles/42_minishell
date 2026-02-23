/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grcharle <grcharle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 12:33:13 by grcharle          #+#    #+#             */
/*   Updated: 2026/02/23 12:33:15 by grcharle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*get_input(void)
{
	char	*input;
	char	buffer[2];
	int		bytes_read;

	input = ft_calloc(sizeof(char), 1);
	if (!input)
		return ((char *) NULL);
	while (1)
	{
		ft_bzero(buffer, 2);
		bytes_read = (int) read(STDIN_FILENO, buffer, 1);
		if (bytes_read < 1 || buffer[0] == '\n')
			break ;
		input = ft_strjoin(input, buffer);
	}
	return (input);
}
