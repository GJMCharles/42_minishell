/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grcharle <grcharle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/22 17:24:35 by grcharle          #+#    #+#             */
/*   Updated: 2026/02/22 17:24:37 by grcharle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	minishell(char *command_line)
{
	printf("%s", command_line);
	return (1);
}

int	main(void)
{
	char	*buffer;
	int		bytes_read;
	int		status;

	status = 1;
	buffer = (char *) ft_calloc(sizeof(char), BUFFER_SIZE + 1);
	if (!buffer)
		return (perror(ERROR_X0), EXIT_FAILURE);
	if (init_minishell_requirements())
	while (status == 1)
	{
		ft_memset(buffer, '\0', BUFFER_SIZE);
		(void) write(STDOUT_FILENO, "$> ", 3);
		bytes_read = (int) read(STDIN_FILENO, buffer, (BUFFER_SIZE - 1));
		if (bytes_read < 0)
			return (free(buffer), perror(ERROR_X1), EXIT_FAILURE);
		status = minishell(buffer);
	}
	free(buffer);
	if (status == -1)
		return (perror(ERROR_X2), EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
