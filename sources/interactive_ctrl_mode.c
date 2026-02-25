/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interactive_ctrl_mode.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grcharle <grcharle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/25 20:54:58 by grcharle          #+#    #+#             */
/*   Updated: 2026/02/25 20:55:09 by grcharle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	enable_interactive_mode(t_minishell *ms)
{
	if (ms->current_keycode == KEY_CTRL_D)
	{
		set_signal_received(1);
	}
	if (ms->current_keycode == KEY_ENTER
		|| ms->current_keycode == KEY_CTRL_C
		|| ms->current_keycode == KEY_CTRL_D)
	{
		ms->add_newline = true;
	}
}
