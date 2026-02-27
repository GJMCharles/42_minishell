/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_utf8.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grcharle <grcharle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/27 07:26:58 by grcharle          #+#    #+#             */
/*   Updated: 2026/02/27 07:27:10 by grcharle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	parse_utf8_char(t_uc c, t_uc **buffer, t_utf8_char *state)
{
	t_uc	*ptr;

	state->utf8_char[state->bytes] = c;
	state->bytes += 1;
	if (state->bytes == state->needed)
	{
		ptr = (t_uc *) ft_recalloc(*buffer, sizeof(t_uc), state->size, state->size + state->needed + 1);
		if (!ptr)
			return (-1);
		ft_memmove(ptr, state->utf8_char, state->needed);
		state->size += state->needed;
		*buffer = ptr;
		return (1);
	}
	return (0);
}

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

t_uc	*get_utf8_char(void)
{
	t_uc		*buffer;
	t_utf8_char	state;
	t_uc		c;

	buffer = (t_uc *) ft_calloc(sizeof(t_uc), 1);
	if (!buffer)
		return (NULL);
	state.bytes = 0;
	state.size = 0;
	while (read(STDIN_FILENO, &c, 1) > 0)
	{
		if (state.bytes == 0)
		{
			ft_bzero(state.utf8_char, 4);
			state.needed = utf8_len(c);
		}
		state.status = parse_utf8_char(c, &buffer, &state);
		if (state.status == -1)
			return (free(buffer), NULL);
		if (state.status == 1)
			break ;
	}
	if (ft_strlen((char *) buffer) == 0)
		return (free(buffer), NULL);
	return (buffer);
}
