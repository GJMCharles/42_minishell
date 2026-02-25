/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_utf8.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grcharle <grcharle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/25 08:13:47 by grcharle          #+#    #+#             */
/*   Updated: 2026/02/25 08:14:04 by grcharle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_ui	utf8_len(t_uc c)
{
	if (c < 0x80)
		return (1);
	if ((c & 0xE0) == 0xC0)
		return (2);
	if ((c & 0xF0) == 0xE0)
		return (3);
	if ((c & 0xF8) == 0xF0)
		return (4);
	return (1);
}

void	assign_char_to_buffer(t_uc **buffer, t_utf8_state *state, t_ui *size)
{
	t_uc	*ptr;

	ptr = (t_uc *) ft_recalloc(*buffer, sizeof(t_uc), *size, *size + state->needed + 1);
	ft_memmove(ptr, state->utf8_char, state->needed);
	*size += state->needed;
	*buffer = ptr;
}

t_uc	*get_utf8_char_from_input(void)
{
	t_uc			*buffer;
	t_utf8_state	state;
	t_ui			size;
	t_uc			c;

	buffer = (t_uc *) ft_calloc(sizeof(t_uc), 1);
	if (!buffer)
		return (NULL);
	state.char_bytes = 0;
	size = 0;
	while (read(STDIN_FILENO, &c, 1) > 0)
	{
		if (state.char_bytes == 0)
		{
			ft_bzero(state.utf8_char, 4);
			state.utf8_char[0] = c;
			state.needed = utf8_len(c);
			if (state.needed == 1)
			{
				assign_char_to_buffer(&buffer, &state, &size);
				break ;
			}
			state.char_bytes += 1;
		}
		else
		{
			state.utf8_char[state.char_bytes] = c;
			state.char_bytes += 1;
			if (state.char_bytes == state.needed)
			{
				assign_char_to_buffer(&buffer, &state, &size);
				break ;
			}
		}
	}
	return (buffer);
}
