/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _command.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grcharle <grcharle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/08 00:01:17 by grcharle          #+#    #+#             */
/*   Updated: 2026/03/08 00:01:19 by grcharle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _COMMAND_H
# define _COMMAND_H

# include "_token.h"

typedef struct s_cmd
{
	char			**args;
	char			*infile;
	char			*outfile;
	char			*heredoc_delimiter;
	int				append_mode;
	int				background;
	int				argc;
}	t_cmd;

typedef struct s_cmd_pipeline
{
	struct s_cmd	**commands;
	int				nb_commands;
	int				*operators;
}	t_cmd_pipeline;

void				handle_heredoc(void);
void				handle_infile(void);
void				handle_append(void);
void				handle_outfile(void);
void				handle_ternary(void);
void				handle_pipe(void);
void				handle_and(void);
void				handle_background(void);

#endif // _COMMAND_H
