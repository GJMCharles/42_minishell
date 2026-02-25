/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_key.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grcharle <grcharle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/25 08:13:19 by grcharle          #+#    #+#             */
/*   Updated: 2026/02/25 08:13:32 by grcharle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

//t_keycode	ctrl_to_keycode(unsigned char c)
//{
//	if (c >= 1 && c <= 26)
//		return (KEY_CTRL_A + (c - 1));
//	if (c == 28)
//		return (KEY_CTRL_BACKSLASH);
//	return (KEY_UNKNOWN);
//}

//t_keycode	arrow_to_keycode(void)
//{
//	unsigned char seq[2];

//	ft_memset(seq, '\0', 2);
//	if (read(STDIN_FILENO, &seq[0], 1) != 1)
//		return (KEY_ESC);
//	if (seq[0] == '[')
//	{
//		if (read(STDIN_FILENO, &seq[1], 1) != 1)
//			return (KEY_UNKNOWN);
//		else if (seq[1] == 'A')
//			return (KEY_UP);
//		else if (seq[1] == 'B')
//			return (KEY_DOWN);
//		else if (seq[1] == 'C')
//			return (KEY_RIGHT);
//		else if (seq[1] == 'D')
//			return (KEY_LEFT);
//		return (KEY_UNKNOWN);
//	}
//	return (KEY_ESC);
//}

//t_keycode	fetch_keychar(unsigned char *ptr)
//{
//	unsigned char	c;

//	if (read(STDIN_FILENO, &c, 1) != 1)
//		return (KEY_UNKNOWN);
//	if (c == '\n' || c == '\r')
//		return (KEY_ENTER);
//	else if (c == 9)
//		return (KEY_TAB);
//	else if (c == 27)
//		return (arrow_to_keycode());
//	else if (c < 32)
//		return (ctrl_to_keycode(c));
//	*ptr = c;
//	return (KEY_NORMAL);
//}
