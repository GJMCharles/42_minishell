/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grcharle <grcharle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/26 06:41:53 by grcharle          #+#    #+#             */
/*   Updated: 2026/02/26 06:42:06 by grcharle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	display_debug_error(char *message)
{
	ft_putstr_fd("\n[DEBUG MODE]: error → ", STDERR_FILENO);
	ft_putstr_fd(message, STDERR_FILENO);
}

void	display_debug_info(char *message)
{
	ft_putstr_fd("\n[DEBUG MODE]: info → ", STDOUT_FILENO);
	ft_putstr_fd(message, STDOUT_FILENO);
}

void	verify_debug_mode_enabled(void)
{
	if (DEBUG_MODE == 1)
		ft_putendl_fd("⛔🐛 [[ DEBUG_MODE enabled ]]", STDOUT_FILENO);
}
