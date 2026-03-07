/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grcharle <grcharle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/02 20:19:51 by grcharle          #+#    #+#             */
/*   Updated: 2026/03/07 14:03:05 by grcharle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# ifndef DEBUG
#  define DEBUG false
# endif

# include "libft.h"
# include "_env.h"
# include "_signals.h"
# include "_token.h"
# include <readline/history.h>
# include <readline/readline.h>

typedef unsigned long int	t_uli;
typedef unsigned int		t_ui;
typedef unsigned char		t_uc;

typedef struct s_shell
{
	t_env					*head_env;
}	t_shell;

void		destroy_minishell(t_shell *minishell);
int			execute_minishell(t_shell *minishell);
int			setup_minishell(t_shell *minishell, char **envp);

#endif
