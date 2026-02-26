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

int	parse_utf8_char(t_uc c, t_uc **b, t_utf8_char *s, t_ui *l)
{
	t_uc	*ptr;

	s->utf8_char[s->char_bytes++] = c;
	if (s->char_bytes == s->needed)
	{
		ptr = (t_uc *) ft_recalloc(*b, sizeof(t_uc), *l, *l + s->needed + 1);
		if (!ptr)
			return (-1);
		ft_memmove(ptr, s->utf8_char, s->needed);
		*l += s->needed;
		*b = ptr;
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

t_uc	*get_utf8_char_from_stdin(void)
{
	t_uc			*buffer;
	t_utf8_char		state;
	t_ui			size;
	t_uc			c;
	int				status;

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
			state.needed = utf8_len(c);
		}
		status = parse_utf8_char(c, &buffer, &state, &size);
		if (status == -1)
			return (NULL);
		if (status == 1)
			break ;
	}
	return (buffer);
}
