/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_line.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grcharle <grcharle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/02 21:13:29 by grcharle          #+#    #+#             */
/*   Updated: 2026/03/02 21:13:40 by grcharle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*get_command_line(char *prompt)
{
	char		*line;
	// t_uc		*c;
	// t_keycode	keycode;

	ft_putstr_fd(prompt, STDOUT_FILENO);
	line = (char *) ft_calloc(sizeof(char), 1);
	if (!line)
		return (NULL);
	while (1)
	{
		// c = get_utf8_char();
		// if (!c)
		// 	return (free(line), NULL);
		// assign_to_keycode(&keycode, c);
		// if (c[0] == '\n' || c[0] == '\0')
		// 	return (free(line), free(c), NULL);
		// line = ft_strjoin(line, (char *) c);

		break ;
	}
	// add_line_to_history(line);
	return (line);
}
