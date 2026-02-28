/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grcharle <grcharle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/26 15:26:03 by grcharle          #+#    #+#             */
/*   Updated: 2026/02/28 00:00:00 by grcharle         ###   ########.fr       */
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

bool	can_exit_input(t_keycode keycode)
{
	return (keycode == KEY_ENTER
		|| keycode == KEY_CTRL_D
		|| keycode == KEY_CTRL_C);
}

static bool	process_char(t_minishell *ms, char **line, t_uc *c)
{
	char	*temp;

	get_keycode(c, &ms->input);
	if (can_exit_input(ms->input.keycode))
		return (false);
	if (ms->input.keycode == KEY_NORMAL
		|| ms->input.keycode == KEY_UNKNOWN)
		ft_putstr_fd((char *)c, STDOUT_FILENO);
	temp = ft_strjoin(*line, (char *)c);
	free(*line);
	*line = temp;
	return (true);
}

void	fetch_input(t_minishell *ms)
{
	char	*command_line;
	t_uc	*c;

	command_line = (char *)ft_calloc(sizeof(char), 1);
	if (!command_line)
		return ;
	while (1)
	{
		clear_input(&ms->input);
		c = get_utf8_char();
		if (!c)
		{
			free(command_line);
			return ;
		}
		if (!process_char(ms, &command_line, c))
		{
			free(c);
			break ;
		}
		free(c);
	}
	ms->command_line = command_line;
}
