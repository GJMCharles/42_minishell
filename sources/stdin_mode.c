/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stdin_mode.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grcharle <grcharle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/24 11:39:01 by grcharle          #+#    #+#             */
/*   Updated: 2026/02/24 11:39:12 by grcharle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void set_raw_mode(struct termios *original)
{
	struct termios	raw;

	tcgetattr(STDIN_FILENO, original);
	raw = *original;
	raw.c_lflag &= ~(ICANON | ECHO | ISIG);
	raw.c_cc[VMIN] = 1;
	raw.c_cc[VTIME] = 0;
	tcsetattr(STDIN_FILENO, TCSAFLUSH, &raw);
}

void restore_mode(struct termios *original)
{
	tcsetattr(STDIN_FILENO, TCSAFLUSH, original);
}
