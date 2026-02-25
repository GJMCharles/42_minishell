/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grcharle <grcharle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/22 17:24:35 by grcharle          #+#    #+#             */
/*   Updated: 2026/02/22 17:24:37 by grcharle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

//int	main(int argc, char *argv[], char *envp[])
//{
//	(void) argc;
//	(void) argv;
//	(void) envp;
	
//	char	*input;
//	struct termios	original_mode;
//	e_keycode		keycode;

//	if (!setup_signal_handlers())
//		return (EXIT_FAILURE);
//	while (1)
//	{
//		if (write(STDOUT_FILENO, "~$> ", 4) == -1)
//			return (perror(ERROR_XA), EXIT_FAILURE);
//		set_raw_mode(&original_mode);
//		input = get_input(&keycode);
//		restore_mode(&original_mode);
//		if (keycode == KEY_CTRL_C)
//			ft_putstr_fd("CTRL + C", STDOUT_FILENO);
//		if (keycode == KEY_CTRL_D)
//			ft_putstr_fd("CTRL + D", STDOUT_FILENO);
//		if (keycode == KEY_CTRL_BACKSLASH)
//			ft_putstr_fd("CTRL + \\", STDOUT_FILENO);
//		//if (input)
//		//{
//		//	ft_putstr_fd(input, STDOUT_FILENO);
//		//	free(input);
//		//}
//		if (write(STDOUT_FILENO, "\n", 1) == -1)
//			return (perror(ERROR_XA), EXIT_FAILURE);
//		//break ;
//	}
//	return (EXIT_SUCCESS);
//}

int	main(void)
{
	char			*input;

	if (!setup_signal_handler())
		return (EXIT_FAILURE);
	while (get_signal_received() == 0)
	{
		if (write(STDOUT_FILENO, "~$> ", 4) == -1)
			return (perror(ERROR_WO), false);
		input = get_input();
		if (write(STDOUT_FILENO, "\n", 1) == -1)
			return (perror(ERROR_WO), false);
		ft_putstr_fd(input, STDOUT_FILENO);
		if (input)
			free(input);
		break ;
	}
	return (EXIT_SUCCESS);
}
