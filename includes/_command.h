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

# ifndef MAX_COMMANDS
#  define MAX_COMMANDS 100
# endif

# ifndef MAX_HEREDOC_LINES
#  define MAX_HEREDOC_LINES 1000
# endif

# ifndef MAX_LINE_LENGTH
#  define MAX_LINE_LENGTH 4096
# endif

# include "libft.h"
# include "_token.h"

typedef struct s_cmd
{
	int					argc;
	char				**args;
	char				*infile;
	char				*outfile;
	char				*heredoc_delimiter;
	int					append_mode;
	int					background;
}	t_cmd;

typedef struct s_cmd_pipeline
{
	struct s_cmd		**commands;
	enum e_token_type	*operators;
	int					nb_commands;
}	t_cmd_pipeline;

typedef struct s_cmd_build
{
	int					expecting_filename;
	int					expecting_heredoc;
	t_token_type		last_token;
}	t_cmd_build;

/**
 * build_command.c
 */
void					build_command_extended_others(t_cmd_pipeline **pipe, t_cmd **cmd);
void					build_command_extended_special(t_cmd_pipeline **pipe, t_cmd **cmd, t_token *token, size_t length);
void					build_command_extended_redirection(t_cmd_build *options, t_token_type token_type);
void					build_command_extended_word(t_cmd_build *options, t_cmd **cmd, char *value);
t_cmd_pipeline			*build_command_pipeline(t_token *tokens);


/**
 * command_pipeline_node.c
 */
void					destroy_command_pipeline(t_cmd_pipeline **pipe);
int						create_command_pipeline(t_cmd_pipeline **pipe);

/**
 * command_node.c
 */
void					destroy_command(t_cmd **cmd);
int						create_command(t_cmd **cmd, size_t max_length);

/**
void					handle_heredoc(void);
void					handle_infile(void);
void					handle_append(void);
void					handle_outfile(void);
void					handle_ternary(void);
void					handle_pipe(void);
void					handle_and(void);
void					handle_background(void);
*/

#endif // _COMMAND_H
