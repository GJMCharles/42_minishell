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

char	*append_char_to_input(char **input, t_uc *c)
{
	size_t	len;

	len = ft_strlen(*input);
	*input = (char *) ft_recalloc(
			*input, sizeof(char), len, len + ft_strlen((char *)c) + 1);
	if (!(*input))
		return (NULL);
	ft_memcpy(*input + len, c, ft_strlen((char *)c));
	return (*input);
}

char	*get_input(t_minishell *ms)
{
	char			*input;
	struct termios	original_mode;
	t_uc			*c;

	input = (char *) ft_calloc(sizeof(char), 1);
	if (!input)
		return (NULL);
	while (1)
	{
		set_raw_mode(&original_mode);
		c = get_utf8_char_from_stdin();
		restore_mode(&original_mode);
		if (!c || !append_char_to_input(&input, c))
			return (NULL);
		ms->current_keycode = fetch_keycode(c[0]);
		if (ms->current_keycode == KEY_NORMAL)
			ft_putstr_fd((char *) c, STDIN_FILENO);
		free(c);
		if (ms->current_keycode == KEY_ENTER
			|| ms->current_keycode == KEY_CTRL_C
			|| ms->current_keycode == KEY_CTRL_D)
			break ;
	}
	return (input);
}
