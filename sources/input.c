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

//void	display_keyboard_keys(char *key)
//{
//	//if (c == KEY_LEFT)
//	//{
//	//	ft_putstr_fd("LEFT\n", STDOUT_FILENO);
//	//}
//	//else if (c == KEY_RIGHT)
//	//{
//	//	ft_putstr_fd("RIGHT\n", STDOUT_FILENO);
//	//}
//}

e_keycode	arrow_to_keycode(void)
{
	unsigned char seq[2];

	ft_memset(seq, '\0', 2);
	if (read(STDIN_FILENO, &seq[0], 1) != 1)
		return (KEY_ESC);
	if (seq[0] == '[')
	{
		if (read(STDIN_FILENO, &seq[1], 1) != 1)
			return (KEY_UNKNOWN);
		else if (seq[1] == 'A')
			return (KEY_UP);
		else if (seq[1] == 'B')
			return (KEY_DOWN);
		else if (seq[1] == 'C')
			return (KEY_RIGHT);
		else if (seq[1] == 'D')
			return (KEY_LEFT);
		else
			return (KEY_UNKNOWN);
	}
	return (KEY_ESC);
}

e_keycode	ctrl_to_keycode(unsigned char c)
{
	if (c >= 1 && c <= 26)
		return (KEY_CTRL_A + (c - 1));
	if (c == 28)
		return (KEY_CTRL_BACKSLASH);
	return (KEY_UNKNOWN);
}

e_keycode	read_key(void)
{
	unsigned char	c;

	if (read(STDIN_FILENO, &c, 1) != 1)
		return (KEY_UNKNOWN);
	if (c == '\n' || c == '\r')
		return (KEY_ENTER);
	if (c == 9)
		return (KEY_TAB);
	if (c == 27)
		return (arrow_to_keycode());
	if (c < 32)
		return (ctrl_to_keycode(c));
	return (KEY_NORMAL);
}

e_keycode	get_input(char **input)
{
	char			*std_input;
	char			buffer[2];
	//int				bytes_read;
	//struct termios	original_mode;

	std_input = ft_calloc(sizeof(char), 1);
	if (!std_input)
		return (KEY_UNKNOWN);
	while (1)
	{
		ft_bzero(buffer, 2);
		if (read(STDIN_FILENO, &buffer[0], 1) != 1)
			return (KEY_UNKNOWN);
		//
		//set_raw_mode(&original_mode);
		//bytes_read = (int) read(STDIN_FILENO, buffer, 1);
		//restore_mode(&original_mode);
		//display_keyboard_keys(buffer);
		//if (bytes_read < 1 || buffer[0] == '\n')
		//	break ;
		//std_input = ft_strjoin(std_input, buffer);
	}
	*input = std_input;
	return (KEY_NORMAL);
}
