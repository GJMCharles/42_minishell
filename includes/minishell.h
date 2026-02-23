/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchanteu <bchanteu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 15:02:08 by bchanteu          #+#    #+#             */
/*   Updated: 2025/11/28 15:54:37 by bchanteu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "libft.h"
# include <stdio.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# endif

# define ERROR_X0 "failed to allocate memory"
# define ERROR_X1 "failed to read standard input"
# define ERROR_X2 "an unexpected error has occured"

typedef struct s_minishell
{
	char	**path;
	char	**env;
}	t_minishell;

int	minishell(char *command_line);

#endif
