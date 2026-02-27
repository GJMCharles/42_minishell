/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_keycode.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grcharle <grcharle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/27 07:27:30 by grcharle          #+#    #+#             */
/*   Updated: 2026/02/27 07:27:43 by grcharle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	append_to_keycode(t_input *input, t_uc *c, t_keycode keycode)
{
	input->keycode = keycode;
	ft_memmove(input->utf8_char, c, ft_strlen((char *) c) + 1);
}

void	ctrl_to_keycode(t_input *input, t_uc *c)
{
	input->is_ctrl = true;
	if (c[0] == 9)
		append_to_keycode(input, c, KEY_TAB);
	else if (c[0] == '\n' || c[0] == '\r')
		append_to_keycode(input, c, KEY_ENTER);
	else if (c[0] >= 1 && c[0] <= 26)
		append_to_keycode(input, c, KEY_CTRL_A + (c[0] - 1));
	else if (c[0] == 28)
		append_to_keycode(input, c, KEY_CTRL_BACKSLASH);
	else
		append_to_keycode(input, c, KEY_UNKNOWN);
}

void	arrow_to_keycode(t_input *input, t_uc *c)
{
	input->utf8_char[0] = 27;
	input->utf8_char[1] = '[';
	if (c[0] == 65)
	{
		append_to_keycode(input, c, KEY_UP);
		input->utf8_char[2] = 'A';
	}
	else if (c[0] == 66)
	{
		append_to_keycode(input, c, KEY_DOWN);
		input->utf8_char[2] = 'B';
	}
	else if (c[0] == 67)
	{
		append_to_keycode(input, c, KEY_RIGHT);
		input->utf8_char[2] = 'C';
	}
	else if (c[0] == 68)
	{
		append_to_keycode(input, c, KEY_LEFT);
		input->utf8_char[2] = 'D';
	}
	else
		input->utf8_char[2] = c[0];
	input->utf8_char[3] = '\0';
}

void	get_keycode(t_uc *c, t_input *input)
{
	t_uc	*x;
	if (!c)
		return ;
	if (c[0] < 32)
		ctrl_to_keycode(input, c);
	else if (c[0] == 27)
	{
		x = get_utf8_char();
		if (x[0] == '[')
		{
			free(x);
			x = get_utf8_char();
			arrow_to_keycode(input, x);
			free(x);
			return ;
		}
		free(x);
		append_to_keycode(input, c, KEY_ESC);
	}
	else
		append_to_keycode(input, c, KEY_NORMAL);
}
