/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grcharle <grcharle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/26 15:26:03 by grcharle          #+#    #+#             */
/*   Updated: 2026/02/26 15:31:28 by grcharle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	clear_input(t_input *input)
{
	input->is_arrow = false;
	input->is_ctrl = false;
	input->is_special = false;
	input->keycode = KEY_UNKNOWN;
	ft_bzero(input->utf8_char, 4);
}

void	fetch_input(t_minishell *ms)
{
	char	*command_line;
	t_uc	*c;

	command_line = (char *) ft_calloc(sizeof(char), 1);
	if (!command_line)
		return ;
	while (1)
	{
		clear_input(&ms->input),
		c = get_utf8_char();
		if (!c)
		{
			free(c), free(command_line);
			return ;
		}
		get_keycode(c, &ms->input);
		if (ms->input.keycode == KEY_ENTER 
			|| ms->input.keycode == KEY_CTRL_D
			|| ms->input.keycode == KEY_CTRL_C)
		{
			free(c);
			break ;
		}
		command_line = ft_strjoin(command_line, (char *) c);
		free(c);
	}
	ms->command_line = command_line;
}
