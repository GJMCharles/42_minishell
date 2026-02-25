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

char* read_utf8_line()
{
	//size_t capacity = 4;
	size_t size = 0;
	char *buffer;
	t_utf8_state	state;

	buffer = (char *) ft_calloc(sizeof(char), 1);
	if (!buffer)
		return (NULL);

	unsigned char c;
	ft_bzero(state.utf8_char, 4);
	state.char_bytes = 0;
	state.needed = 0;

	while (read(STDIN_FILENO, &c, 1) > 0) {
		if (c == '\n' || c == '\r')
			break;

		if (state.char_bytes == 0) {
			state.utf8_char[0] = c;
			state.needed = utf8_len(c); // 4
			state.char_bytes = 1;
			if (state.needed == 1)
			{
				buffer = (char *) ft_recalloc(buffer, sizeof(char), size, size + 2);
				buffer[size++] = c;
				state.char_bytes = 0;
			}
		}
		else
		{
			state.utf8_char[state.char_bytes] = c;
			state.char_bytes += 1;
			if (state.char_bytes == state.needed)
			{
				buffer = (char *) ft_recalloc(buffer, sizeof(char), size, size + state.needed + 1);
				unsigned int i = 0;
				while (i < state.needed)
				{
					buffer[size] = state.utf8_char[i];
					size += 1;
					i += 1;
				}
				state.char_bytes = 0;
			}
		}
	}
	return buffer;
}

char	*build_string(unsigned int c)
{
	t_utf8_state	state;

	(void) c;
	ft_memset(state.utf8_char, '\0', 4);
	state.char_bytes = 0;
	state.needed = 0;
	return (NULL);
}



char	*get_input(void)
{
	char			*input;
	struct termios	original_mode;
	//t_keycode		keycode;
	t_uc			*c;

	input = (char *) ft_calloc(sizeof(char), 1);
	if (!input)
		return (NULL);
	while (1)
	{
		set_raw_mode(&original_mode);
		c = get_utf8_char_from_input();
		restore_mode(&original_mode);
		ft_putstr_fd("*~~~", STDOUT_FILENO);
		ft_putstr_fd((char *)c, STDOUT_FILENO);
		ft_putstr_fd("~~~*\n", STDOUT_FILENO);
		free(c);
		break ;
	}
	return (input);
}
