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

t_keycode	ctrl_to_keycode(t_uc c)
{
	if (c >= 1 && c <= 26)
		return (KEY_CTRL_A + (c - 1));
	if (c == 28)
		return (KEY_CTRL_BACKSLASH);
	return (KEY_UNKNOWN);
}

t_keycode	arrow_to_keycode(void)
{
	ft_putstr_fd("\033[D", STDIN_FILENO);
	//unsigned char	seq[2];
	//ft_putnbr_fd(1, STDIN_FILENO);
	//if (read(STDIN_FILENO, &seq[0], 1) == 1 && seq[0] == '[')
	//{
	//	if (read(STDIN_FILENO, &seq[1], 1) == 1)
	//	{
	//		switch (seq[1])
	//		{
	//			case 'A': ft_putstr_fd("UP arrow\n", STDIN_FILENO); break;
	//			case 'B': ft_putstr_fd("DOWN arrow\n", STDIN_FILENO); break;
	//			case 'C': ft_putstr_fd("RIGHT arrow\n", STDIN_FILENO); break;
	//			case 'D': ft_putstr_fd("LEFT arrow\n", STDIN_FILENO); break;
	//			default: ft_putstr_fd("Unknown ESC sequence\n", STDIN_FILENO);
	//		}
	//	}
	//}

	//ft_bzero(seq, 2);
	//if (read(STDIN_FILENO, &seq[0], 1) != 1)
	//	return (KEY_ESC);
	//ft_putnbr_fd(seq[0], STDIN_FILENO);
	//ft_putstr_fd("[0]", STDIN_FILENO);
	//if (read(STDIN_FILENO, &seq[1], 1) != 1)
	//	return (KEY_ESC);
	//ft_putnbr_fd(seq[1], STDIN_FILENO);
	//ft_putstr_fd("[1]", STDIN_FILENO);

	//if (seq[0] == '[')
	//{
	//	if (read(STDIN_FILENO, &seq[1], 1) != 1)
	//		return (KEY_UNKNOWN);
	//	else if (seq[1] == 'A')
	//	{
	//		ft_putstr_fd("[KEY_UP]", STDIN_FILENO);
	//		return (KEY_UP);
	//	}
	//	else if (seq[1] == 'B')
	//	{
	//		ft_putstr_fd("[KEY_DOWN]", STDIN_FILENO);
	//		return (KEY_DOWN);
	//	}
	//	else if (seq[1] == 'C')
	//	{
	//		ft_putstr_fd("[KEY_RIGHT]", STDIN_FILENO);
	//		return (KEY_RIGHT);
	//	}
	//	else if (seq[1] == 'D')
	//	{
	//		ft_putstr_fd("[KEY_LEFT]", STDIN_FILENO);
	//		return (KEY_LEFT);
	//	}
	//	return (KEY_UNKNOWN);
	//}
	return (KEY_ESC);
}

t_keycode	fetch_keycode(t_uc	*c)
{
	//if (c == '\n' || c == '\r')
	//	return (KEY_ENTER);
	//else if (c == '\t')
	//	return (KEY_TAB);
	//else if (c == 27)
	//	return (arrow_to_keycode());
	//else if (c < 32)
	//	return (ctrl_to_keycode(c));
	//return (KEY_NORMAL);

	int	i;
	i = 0;
	ft_putchar_fd('[', STDOUT_FILENO);
	while (c[i])
	{
		ft_putnbr_fd(c[i++], STDOUT_FILENO);
		ft_putchar_fd('.', STDOUT_FILENO);
	}
	ft_putchar_fd(']', STDOUT_FILENO);

	t_uc seq[2];

	ft_bzero(seq, 2);
	if (read(STDIN_FILENO, &seq[0], 1) != 1)
		ft_putstr_fd("[X]", STDOUT_FILENO);
	i = 0;
	ft_putchar_fd('{', STDOUT_FILENO);
	while (seq[i])
	{
		ft_putnbr_fd(seq[i++], STDOUT_FILENO);
		ft_putchar_fd('.', STDOUT_FILENO);
	}
	ft_putchar_fd('}', STDOUT_FILENO);
	
    //if (read(STDIN_FILENO, &c, 1) != 1)
    //    return KEY_UNKNOWN;
    
    //// Check for ESC sequences
    //if (c == 27) {
    //    char seq[2];
    //    if (read(STDIN_FILENO, &seq[0], 1) != 1)
    //        return KEY_ESC;
            
    //    if (seq[0] == '[') {
    //        if (read(STDIN_FILENO, &seq[1], 1) != 1)
    //            return KEY_UNKNOWN;
                
    //        switch (seq[1]) {
    //            case 'A':
	//				//ft_putstr_fd("⬆️", STDOUT_FILENO);
	//				return KEY_UP;
    //            case 'B':
	//				//ft_putstr_fd("⬇️", STDOUT_FILENO);
	//				return KEY_DOWN;
    //            case 'C':
	//				//ft_putstr_fd("➡️", STDOUT_FILENO);
	//				return KEY_RIGHT;
    //            case 'D':
	//				//ft_putstr_fd("⬅️", STDOUT_FILENO);
	//				return KEY_LEFT;
    //            default:
	//				return KEY_UNKNOWN;
    //        }
    //    }
    //    return (KEY_ESC);
    //}
    //// Check for TAB
    //if (c == 9)
    //    return (KEY_TAB);
    return (KEY_CTRL_D);
}
