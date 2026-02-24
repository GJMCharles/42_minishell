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

void set_raw_mode(struct termios *original)
{
	struct termios raw;

	tcgetattr(STDIN_FILENO, original);
	raw = *original;
	// Disable canonical mode and echo
	raw.c_lflag &= (unsigned int) ~(ICANON | ECHO);
	// Set minimum read to 1 character
	raw.c_cc[VMIN] = 1;
	raw.c_cc[VTIME] = 0;
	tcsetattr(STDIN_FILENO, TCSAFLUSH, &raw);
}

void restore_mode(struct termios *original)
{
	tcsetattr(STDIN_FILENO, TCSAFLUSH, original);
}

char	*get_input(void)
{
	char			*input;
	char			buffer[2];
	int				bytes_read;
	struct termios	original_mode;

	input = ft_calloc(sizeof(char), 1);
	if (!input)
		return (NULL);

	while (1)
	{
		ft_bzero(buffer, 2);
		set_raw_mode(&original_mode);
		bytes_read = (int) read(STDIN_FILENO, buffer, 1);
		restore_mode(&original_mode);
		if (bytes_read < 1 || buffer[0] == '\n')
			break ;
		input = ft_strjoin(input, buffer);
		break ;
	}
	return (input);
}
